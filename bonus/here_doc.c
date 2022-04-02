/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:49:54 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 18:29:25 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_filling_struct(t_bdata *data, char **argv, char **envp, int argc)
{
	data->size_st = ft_strlen(argv[2]);
	data->ar = argv;
	data->en = envp;
	data->fd = 1;
	data->qtt_cmd = 2;
	if (envp != NULL && ft_creating_a_path_b(envp, &argc))
	{
		data->path = ft_split(envp[argc] + 5, ':');
		if (!data->path)
			ft_exit(data, 2);
	}
	argc = 0;
	data->pipe = malloc(sizeof(int *) * 2);
	if (!data->pipe)
		ft_exit(data, 2);
	while (argc < 2)
	{
		data->pipe[argc] = malloc(sizeof(int) * 2);
		if (!data->pipe[argc])
			ft_exit(data, 2);
		if (pipe(data->pipe[argc]))
			ft_exit(data, 3);
		argc++;
	}
}

void	ft_read_in_pipe(t_bdata *data)
{
	char	*str;
	int		flag;

	flag = 1;
	close(data->pipe[0][0]);
	close(data->pipe[1][0]);
	close(data->pipe[1][1]);
	while (flag)
	{
		str = get_next_line(0);
		if (str == NULL)
			ft_close_exit(data, 7);
		if (ft_memcmp(str, data->ar[2], data->size_st) == data->size_st)
		{
			free(str);
			flag = 0;
		}
		else
		{
			ft_putstr_fd(str, data->pipe[0][1]);
			free(str);
		}
	}
	close(data->pipe[0][1]);
}

void	ft_go_to_fork(t_bdata *data, int i)
{
	int	status;

	i = 0;
	while (i < 2)
	{
		data->pid = fork();
		if (data->pid == -1)
			ft_exit(data, 4);
		else if (data->pid == 0 && i == 0)
			ft_from_pipe_to_pipe(data);
		else if (data->pid == 0 && i == 1)
			ft_writing_to_file(data);
		i++;
	}
	ft_read_in_pipe(data);
	while (i > 0)
	{
		if (wait(&status) == -1)
			ft_exit(data, 8);
		i--;
	}
}

void	ft_here_doc(t_bdata *data, char **argv, char **envp, int argc)
{
	argc = 0;
	ft_filling_struct(data, argv, envp, argc);
	ft_go_to_fork(data, argc);
	ft_django_unchained_b(data->path);
	if (data->pipe != NULL)
	{
		while (argc != 2)
		{
			free(data->pipe[argc]);
			argc++;
		}
		free(data->pipe);
		data->pipe = NULL;
	}
}
