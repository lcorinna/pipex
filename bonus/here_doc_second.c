/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:55:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 18:29:05 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_cut_cmd_h(t_bdata *data, int cmd)
{
	int	i;

	i = 0;
	data->command = malloc(sizeof(char *) * 2);
	if (data->command == NULL)
		ft_exit(data, 2);
	data->command[0] = data->ar[cmd];
	data->command[1] = NULL;
	while (*data->command[0])
	{
		if (*data->command[0] == '/')
			i++;
		data->command[0]++;
	}
	data->command[0] = data->ar[cmd];
	while (i)
	{
		if (*data->command[0] == '/')
			i--;
		data->command[0]++;
	}
}

void	ft_full_path_ptp(t_bdata *data)
{
	if (dup2(data->pipe[0][0], 0) == -1)
		ft_exit(data, 5);
	if (dup2(data->pipe[1][1], 1) == -1)
		ft_exit(data, 5);
	ft_cut_cmd_h(data, 3);
	close(data->pipe[0][0]);
	close(data->pipe[1][1]);
	execve(data->ar[3], &data->command[0], data->en);
	ft_exit(data, 9);
}

void	ft_from_pipe_to_pipe(t_bdata *data)
{
	close(data->pipe[0][1]);
	close(data->pipe[1][0]);
	if (data->ar[3][0] == '/' && (access(data->ar[3], F_OK) == 0))
		ft_full_path_ptp(data);
	data->command = ft_split(data->ar[3], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);
	ft_add_program_path(data, data->i);
	while (data->fd != 0 && data->path2[data->i] != NULL)
		data->fd = access(data->path2[data->i++], F_OK);
	if (data->fd == -1)
		ft_close_exit(data, 3);
	data->i--;
	if (dup2(data->pipe[0][0], 0) == -1)
		ft_exit(data, 5);
	if (dup2(data->pipe[1][1], 1) == -1)
		ft_exit(data, 5);
	close(data->pipe[0][0]);
	close(data->pipe[1][1]);
	if (execve(data->path2[data->i], data->command, data->en) == -1)
		ft_close_exit(data, 5);
}

void	ft_full_path_wtf(t_bdata *data)
{
	data->fd = open(data->ar[5], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->fd == -1)
		ft_close_exit(data, 6);
	if (dup2(data->fd, 1) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[1][0], 0) == -1)
		ft_close_exit(data, 1);
	ft_cut_cmd_h(data, 4);
	close(data->fd);
	close(data->pipe[1][0]);
	if (execve(data->path2[data->i], &data->command[0], data->en) == -1)
		ft_close_exit(data, 2);
}

void	ft_writing_to_file(t_bdata *data)
{
	close(data->pipe[0][0]);
	close(data->pipe[0][1]);
	close(data->pipe[1][1]);
	if (data->ar[3][0] == '/' && (access(data->ar[3], F_OK) == 0))
		ft_full_path_wtf(data);
	data->command = ft_split(data->ar[4], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);
	ft_add_program_path(data, data->i);
	while (data->fd != 0 && data->path2[data->i] != NULL)
		data->fd = access(data->path2[data->i++], F_OK);
	if (data->fd == -1)
		ft_close_exit(data, 3);
	data->i--;
	data->fd = open(data->ar[5], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->fd == -1)
		ft_close_exit(data, 6);
	if (dup2(data->fd, 1) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[1][0], 0) == -1)
		ft_close_exit(data, 1);
	close(data->fd);
	close(data->pipe[1][0]);
	if (execve(data->path2[data->i], data->command, data->en) == -1)
		ft_close_exit(data, 2);
}
