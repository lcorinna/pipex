/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:21:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/25 17:39:26 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_cleaning_memory(t_bdata *data)
{
	int	i;

	i = 0;
	if (data->pipe != NULL)
	{
		printf("\nhere\n\n"); //del
		printf("data->n_cmd %d\n", data->n_cmd); //del
		while (i != data->qtt_cmd)
		{
			printf("data->pipe[%d] - %p\n", i, data->pipe[i]); //del
			free(data->pipe[i]);
			i++;
		}
		free(data->pipe);
		data->pipe = NULL;
	}
	printf("data->path %p\n", data->path); //del
	if (data->path != NULL)
		ft_django_unchained(data->path);
	printf("data->cmd %p\n", data->cmd); //del
	if (data->cmd != NULL)
		ft_django_unchained(data->cmd);
	printf("data->path2 %p\n", data->path2); //del
	if (data->path2 != NULL)
		ft_django_unchained(data->path2);
}

void	ft_exit(t_bdata *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Check that the input is correct.\n\
Try writing ./pipex file 1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Malloc does not allocate memory\n", 2);
	else if (flag == 3)
		ft_putstr_fd("The \"pipe\" function does not work\n", 2);
	else if (flag == 4)
		ft_putstr_fd("The \"fork\" function does not work\n", 2);
	else if (flag == 5)
		ft_putstr_fd("The \"open\" function does not work\n", 2);
	else if (flag == 6)
		ft_putstr_fd("The \"split\" function does not work\n", 2);
	else if (flag == 7)
		ft_putstr_fd("The \"strjoin\" function does not work\n", 2);
	else if (flag == 8)
		ft_putstr_fd("The \"access\" function does not work\n", 2);
	ft_cleaning_memory(data);
	exit(1);
}

void	ft_close_exit(t_bdata *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("The \"dup2\" function does not work\n", 2);
	else if (flag == 2)
		ft_putstr_fd("The \"execve\" function does not work\n", 2);
	else if (flag == 3)
		ft_putstr_fd("The \"dup2\" function does not work\n", 2);
	else if (flag == 4)
		ft_putstr_fd("The \"execve\" function does not work\n", 2);
	close(data->fd);
	ft_cleaning_memory(data);
	exit(1);
}
