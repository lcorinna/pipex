/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:21:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/01 17:31:51 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_creating_a_path_b(char **envp, int *num)
{
	int	check;

	check = 0;
	while (envp[*num] != NULL && check != 4)
		check = ft_memcmp("PATH", envp[(*num)++], 4);
	if (check != 4)
		return (0);
	(*num)++;
	return (1);
}

void	ft_django_unchained_b(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	ft_cleaning_memory(t_bdata *data, int flag)
{
	int	i;

	i = 0;
	if (data->pipe != NULL)
	{
		while (i != data->qtt_cmd)
		{
			free(data->pipe[i]);
			i++;
		}
		free(data->pipe);
		data->pipe = NULL;
	}
	if (flag == 1 && data->path != NULL)
		ft_django_unchained_b(data->path);
	if (flag == 2 && data->path2 != NULL)
		ft_django_unchained_b(data->path2);
	if (data->command != NULL)
		ft_django_unchained_b(data->command);
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
		ft_putstr_fd("The \"dup2\" function does not work\n", 2);
	else if (flag == 6)
		ft_putstr_fd("The \"split\" function does not work\n", 2);
	else if (flag == 7)
		ft_putstr_fd("The \"strjoin\" function does not work\n", 2);
	else if (flag == 8)
		ft_putstr_fd("The \"wait\" function does not work\n", 2);
	else if (flag == 9)
		ft_putstr_fd("The \"execve\" function does not work\n", 2);
	ft_cleaning_memory(data, 1);
	exit(1);
}

void	ft_close_exit(t_bdata *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("The \"dup2\" function does not work\n", 2);
	else if (flag == 2)
		ft_putstr_fd("The \"execve\" function does not work\n", 2);
	else if (flag == 3)
		ft_putstr_fd("The \"access\" function does not work\n", 2);
	else if (flag == 4)
		ft_putstr_fd("The \"dup2\" function does not work\n", 2);
	else if (flag == 5)
		ft_putstr_fd("The \"execve\" function does not work\n", 2);
	else if (flag == 6)
		ft_putstr_fd("The \"open\" function does not work\n", 2);
	if (flag < 3)
		close(data->fd);
	ft_cleaning_memory(data, 2);
	exit(1);
}
