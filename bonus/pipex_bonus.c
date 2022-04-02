/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 18:22:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_memory_allocation(t_bdata *data, int argc)
{
	int	i;

	i = 0;
	data->n_cmd = 2;
	data->fd = 1;
	data->qtt_cmd = argc - 4;
	data->pipe = malloc(sizeof(int *) * data->qtt_cmd);
	if (!data->pipe)
		ft_exit(data, 2);
	while (i != data->qtt_cmd)
	{
		data->pipe[i] = malloc(sizeof(int) * 2);
		if (!data->pipe[i])
			ft_exit(data, 2);
		i++;
	}
}

void	ft_filling_data(t_bdata *data, int argc, char **envp)
{
	if (argc < 5)
		ft_exit(data, 1);
	ft_memory_allocation(data, argc);
	argc = 0;
	if (envp != NULL && ft_creating_a_path_b(envp, &argc))
	{
		data->path = ft_split(envp[argc] + 5, ':');
		if (data->path == NULL)
			ft_exit(data, 2);
	}
	argc = 0;
	while (argc < data->qtt_cmd)
	{
		if (pipe(data->pipe[argc]))
			ft_exit(data, 3);
		argc++;
	}
}

void	ft_close_all_pipes(t_bdata *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->qtt_cmd)
	{
		j = 0;
		while (j != 2)
			close(data->pipe[i][j++]);
		i++;
	}
}

void	ft_making_processes(t_bdata *data, char **argv, char **envp)
{
	int	status;

	while (data->n_child <= data->qtt_cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			ft_exit(data, 4);
		else if (data->pid == 0 && data->n_child == 0)
			ft_first_entry(data, envp, argv);
		else if (data->pid == 0 && data->n_child == data->qtt_cmd)
			ft_last_entry(data, envp, argv);
		else if (data->pid == 0)
			ft_routine(data, envp, argv);
		data->n_child++;
		data->n_cmd++;
	}
	ft_close_all_pipes(data);
	while (data->n_child > 0)
	{
		if (wait(&status) == -1)
			ft_exit(data, 8);
		data->n_child--;
	}
}

int	main(int argc, char **argv, char **envp)
{	
	t_bdata	data;

	data = (t_bdata){};
	if (ft_memcmp("here_doc", argv[1], 9) == 9 && argc == 6)
		ft_here_doc(&data, argv, envp, argc);
	else
	{
		ft_filling_data(&data, argc, envp);
		ft_making_processes(&data, argv, envp);
		ft_cleaning_memory(&data, 2);
	}	
	return (0);
}
