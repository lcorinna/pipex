/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:21:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 19:16:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_cleaning_memory(t_bdata *data)
{
	if (data->path != NULL)
		ft_django_unchained(data->path);
	if (data->pipe != NULL)
		ft_django_unchained(data->pipe);
	if (data->cmd != NULL)
		ft_django_unchained(data->cmd);
}

void	ft_exit(t_bdata *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Check that the input is correct.\n\
Try writing ./pipex file 1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Malloc does not allocate memory\n", 2);
	else if (flag == 3)
		ft_putstr_fd("The pipe function does not work\n", 2);
	else if (flag == 4)
		ft_putstr_fd("The \"fork\" function does not work\n"", 2);
	ft_cleaning_memory(data);
	exit(1);
}
