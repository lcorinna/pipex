/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 19:21:14 by lcorinna         ###   ########.fr       */
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
}

void	ft_first(char **argv, t_data *data, char **envp)
{
	int	i;

	i = 0;
	// data->i = 0;
	if (argv[2][0] == '\\')
		access(data->path[data->i++], F_OK);
	data->command = ft_split(argv[2], ' ');
	if (data->command == NULL)
		ft_exit_with_cleaning(data, NULL, 6);
	data->path = ft_adding_program_to_the_path(data, data->i);
	close(data->pepsi[0]);
	while (data->fd != 0 && data->path[data->i] != NULL)
		data->fd = access(data->path[data->i++], F_OK);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, 1);
	data->i--;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, -2);
	if (dup2(data->fd, 0) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	if (dup2(data->pepsi[1], 1) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	if (execve(data->path[data->i], data->command, envp) == -1)
		ft_exit_with_cleaning(data, NULL, 4);
}

void	ft_making_processes(t_bdata *data, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 2; //send to func. This num cmd
	while (i < data->quantity_cmd)
	{
		if (pipe(data->pipe[i]))
			ft_exit(data, 3);
		i++;
	}
	i = 0;
	while (i < data->quantity_cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			ft_exit(data, 4);
		else if (data->pid == 0 && i == 0)
			// func;
		// else if (data->pid == 0)
		// 	// func;
		i++;
		j++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_bdata	data;
	int		i; //del

	i = 0;
	ft_filling_data(&data, argc, envp);
	ft_making_processes(&data, argv);
	argv = NULL;
	return (0);
}

// ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2