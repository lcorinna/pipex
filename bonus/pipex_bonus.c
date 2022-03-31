/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/31 19:47:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_memory_allocation(t_bdata *data, int argc)
{
	int	i;

	i = 0;
	data->n_cmd = 2;
	data->fd = 1;
	// printf("argc %d\n", argc); //del
	data->qtt_cmd = argc - 4;
	// printf("data->qtt_cmd %d\n", data->qtt_cmd); //del
	data->pipe = malloc(sizeof(int *) * data->qtt_cmd);
	if (!data->pipe)
		ft_exit(data, 2);
	while (i != data->qtt_cmd)
	{
		// printf("i - %d\n", i); //del
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
	if (envp != NULL && ft_creating_a_path(envp, &argc))
	{
		data->path = ft_split(envp[argc] + 5, ':');
		if (data->path == NULL)
			ft_exit(data, 2);
	}
	argc = 0;
	while (argc < data->qtt_cmd)
	{
		// printf("argc %d\n", argc); //del
		if (pipe(data->pipe[argc]))
			ft_exit(data, 3);
		// printf("data->pipe[argc][0] %d \n", data->pipe[argc][0]);
		// printf("data->pipe[argc][1] %d \n", data->pipe[argc][1]);
		argc++;
	}
}

void	ft_making_processes(t_bdata *data, char **argv, char **envp)
{
	int	status;

	// printf("data->n_child %d\n", data->n_child); //del
	printf("data->qtt_cmd %d\n", data->qtt_cmd); //del
	printf("data->n_cmd %d\n", data->n_cmd); //del 
	printf("argv[data->qtt_cmd + 3] %s\n\n", argv[data->qtt_cmd + 3]); //del
	while (data->n_child <= data->qtt_cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			ft_exit(data, 4);
		else if (data->pid == 0 && data->n_child == 0)
		{
			printf("\n1 CHILD %d\n", data->n_child); //del
			printf("command %s\n", argv[data->n_cmd]); //del
			ft_first_entry(data, envp, argv);
		}
		else if (data->pid == 0 && data->n_child == data->qtt_cmd)
		{
			printf("\n3 CHILD %d\n", data->n_child); //del
			printf("command %s\n", argv[data->n_cmd]); //del
			ft_last_entry(data, envp, argv);
		}
		else if (data->pid == 0)
		{
			printf("\n2 CHILD %d\n", data->n_child); //del
			printf("command %s\n", argv[data->n_cmd]); //del
			ft_routine(data, envp, argv);
		}
		data->n_child++;
		data->n_cmd++;
	}
	printf("\nend  CHILD %d\n", data->n_child); //del
	// close all pipe
	while (data->n_child > 0)
	{
		if (wait(&status) == -1)
			exit(11); //del
		data->n_child--;
		printf("\nwh  CHILD %d\n", data->n_child); //del
	}		
	printf("PARENT %d\n", data->n_child); //del
}

int	main(int argc, char **argv, char **envp)
{	
	t_bdata	data;

	data = (t_bdata){};
	ft_filling_data(&data, argc, envp);
	ft_making_processes(&data, argv, envp);
	return (0);
}
