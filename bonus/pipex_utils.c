/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:21:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/21 19:22:08 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_exit(t_bdata *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Check that the input is correct.\n\
Try writing ./pipex file 1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2);
	if (data->path != NULL)
		ft_django_unchained(data->path);
	exit(1);
}
