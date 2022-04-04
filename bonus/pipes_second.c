/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:27:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 19:08:17 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_pipe_closure(t_bdata *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->qtt_cmd)
	{
		j = 0;
		while (j != 2)
		{
			if (data->n_child != i && data->n_child - 1 != i)
				close(data->pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_taking_care_of_norminette(char **path, char *str)
{
	if (str != NULL)
		free(str);
	ft_django_unchained_b(path);
}

void	ft_check_full_path_first(t_bdata *data, char **argv, char **envp)
{
	if (access(argv[data->n_cmd], F_OK))
		return ;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		ft_exit(data, 5);
	if (dup2(data->fd, 0) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[data->n_child][1], 1) == -1)
		ft_close_exit(data, 1);
	ft_cut_cmd(data, argv);
	close(data->fd);
	close(data->pipe[data->n_child][1]);
	execve(argv[data->n_cmd], &data->command[0], envp);
	ft_close_exit(data, 2);
}

void	ft_check_full_path_last(t_bdata *data, char **argv, char **envp)
{
	if (access(argv[data->n_cmd], F_OK))
		return ;
	data->fd = open(argv[data->qtt_cmd + 3], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd == -1)
		ft_exit(data, 5);
	if (dup2(data->fd, 1) == -1)
		ft_close_exit(data, 1);
	if (dup2(data->pipe[data->n_child - 1][0], 0) == -1)
		ft_close_exit(data, 1);
	ft_cut_cmd(data, argv);
	close(data->fd);
	close(data->pipe[data->n_child - 1][0]);
	execve(argv[data->n_cmd], &data->command[0], envp);
	ft_close_exit(data, 2);
}

void	ft_check_full_path_routine(t_bdata *data, char **argv, char **envp)
{
	if (access(argv[data->n_cmd], F_OK))
		return ;
	if (dup2(data->pipe[data->n_child - 1][0], 0) == -1)
		ft_exit(data, 5);
	if (dup2(data->pipe[data->n_child][1], 1) == -1)
		ft_exit(data, 5);
	ft_cut_cmd(data, argv);
	close(data->pipe[data->n_child - 1][0]);
	close(data->pipe[data->n_child][1]);
	execve(argv[data->n_cmd], &data->command[0], envp);
	ft_exit(data, 9);
}
