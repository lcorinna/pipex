/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:33:27 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 13:13:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_add_program_path(t_bdata *data, int i)
{
	char	*str;

	str = ft_strjoin("/", data->command[0]);
	if (str == NULL)
		ft_exit(data, 7);
	while (data->path != NULL && data->path[i])
		i++;
	data->path2 = (char **) malloc(sizeof (char *) * (i + 2));
	if (data->path2 == NULL)
		ft_exit(data, 2);
	i = 0;
	while (data->path != NULL && data->path[i])
	{
		data->path2[i] = ft_strjoin(data->path[i], str);
		if (data->path2[i] == NULL)
			ft_exit(data, 7);
		i++;
	}
	data->path2[i++] = ft_strjoin("./", data->command[0]);
	if (data->path2[i - 1] == NULL)
		ft_exit(data, 7);
	data->path2[i] = NULL;
	ft_taking_care_of_norminette(data->path, str);
}

void	ft_cut_cmd(t_bdata *data, char **argv)
{
	int	i;

	i = 0;
	data->command = malloc(sizeof(char *) * 2);
	if (data->command == NULL)
		ft_exit(data, 2);
	data->command[0] = argv[data->n_cmd];
	data->command[1] = NULL;
	while (*data->command[0])
	{
		if (*data->command[0] == '/')
			i++;
		data->command[0]++;
	}
	data->command[0] = argv[data->n_cmd];
	while (i)
	{
		if (*data->command[0] == '/')
			i--;
		data->command[0]++;
	}
}

void	ft_first_entry(t_bdata *data, char **envp, char **argv)
{
	close(data->pipe[data->n_child][0]);
	ft_pipe_closure(data);
	if (argv[data->n_cmd][0] == '/')
		ft_check_full_path_first(data, argv, envp);
	data->command = ft_split(argv[data->n_cmd], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);
	ft_add_program_path(data, data->i);
	while (data->fd != 0 && data->path2[data->i] != NULL)
		data->fd = access(data->path2[data->i++], F_OK);
	if (data->fd == -1)
		ft_close_exit(data, 3);
	data->i--;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		ft_close_exit(data, 6);
	if (dup2(data->fd, 0) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[data->n_child][1], 1) == -1)
		ft_close_exit(data, 1);
	close(data->fd);
	close(data->pipe[data->n_child][1]);
	if (execve(data->path2[data->i], data->command, envp) == -1)
		ft_close_exit(data, 2);
}

void	ft_last_entry(t_bdata *data, char **envp, char **argv)
{
	close(data->pipe[data->n_child - 1][1]);
	ft_pipe_closure(data);
	if (argv[data->n_cmd][0] == '/')
		ft_check_full_path_last(data, argv, envp);
	data->command = ft_split(argv[data->n_cmd], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);
	ft_add_program_path(data, data->i);
	while (data->fd != 0 && data->path2[data->i] != NULL)
		data->fd = access(data->path2[data->i++], F_OK);
	if (data->fd == -1)
		ft_close_exit(data, 3);
	data->i--;
	data->fd = open(argv[data->qtt_cmd + 3], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd == -1)
		ft_close_exit(data, 6);
	if (dup2(data->fd, 1) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[data->n_child - 1][0], 0) == -1)
		ft_close_exit(data, 1);
	close(data->fd);
	close(data->pipe[data->n_child - 1][0]);
	if (execve(data->path2[data->i], data->command, envp) == -1)
		ft_close_exit(data, 2);
}

void	ft_routine(t_bdata *data, char **envp, char **argv)
{
	close(data->pipe[data->n_child - 1][1]);
	close(data->pipe[data->n_child][0]);
	ft_pipe_closure(data);
	if (argv[data->n_cmd][0] == '/')
		ft_check_full_path_routine(data, argv, envp);
	data->command = ft_split(argv[data->n_cmd], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);
	ft_add_program_path(data, data->i);
	while (data->fd != 0 && data->path2[data->i] != NULL)
		data->fd = access(data->path2[data->i++], F_OK);
	if (data->fd == -1)
		ft_close_exit(data, 3);
	data->i--;
	if (dup2(data->pipe[data->n_child - 1][0], 0) == -1)
		ft_close_exit(data, 4);
	if (dup2(data->pipe[data->n_child][1], 1) == -1)
		ft_close_exit(data, 4);
	close(data->pipe[data->n_child - 1][0]);
	close(data->pipe[data->n_child][1]);
	if (execve(data->path2[data->i], data->command, envp) == -1)
		ft_close_exit(data, 5);
}
