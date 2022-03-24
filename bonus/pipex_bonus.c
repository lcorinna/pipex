/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/24 16:34:57 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_memory_allocation(t_bdata *data, int argc)
{
	int	i;

	i = 0;
	data->quantity_cmd = argc - 3;
	data->pipe = malloc(sizeof(int *) * data->quantity_cmd);
	if (!data->pipe)
		ft_exit(data, 2);
	while (i != data->quantity_cmd)
	{
		data->pipe[i] = malloc(sizeof(int) * 2);
		if (!data->pipe[i])
			ft_exit(data, 2);
		i++;
	}
}

void	ft_filling_data(t_bdata *data, int argc, char **envp)
{	
	data->path = NULL;
	data->pipe = NULL;
	data->cmd = NULL;
	data->command = NULL;
	data->n_cmd = 2;
	data->fd = 1;
	data->i = 0;
	if (argc < 5)
		ft_exit(data, 1);
	ft_memory_allocation(data, argc);
	argc = 0;
	if (envp != NULL && ft_creating_a_path(envp, &argc))
	{
		data->path = ft_split(envp[argc] + 5, ':');
		if (data->path == NULL)
			ft_exit(data, 2);
	}
	argc = 0;
	while (argc < data->quantity_cmd)
	{
		if (pipe(data->pipe[argc]))
			ft_exit(data, 3);
		argc++;
	}
}

void	ft_making_processes(t_bdata *data, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < data->quantity_cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			ft_exit(data, 4);
		else if (data->pid == 0 && i == 0)
			ft_first_entry(data, envp, argv);
		// else if (data->pid == 0)
		// 	// func;
		i++;
		data->n_cmd++;
	}
}

int	main(int argc, char **argv, char **envp)
{	
	t_bdata	data;

	ft_filling_data(&data, argc, envp);
	ft_making_processes(&data, argv, envp);
	argv = NULL;
	return (0);
}
