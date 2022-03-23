/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_workers_go_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:50:38 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 17:49:50 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exit_with_cleaning(t_data *data, char **p8, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Sorry, bro, I didn't find the \"", 2);
		ft_putstr_fd(data->command[0], 2);
		write(2, "\" command\n", 10);
	}
	else if (flag == 2)
		ft_putstr_fd("\"open\" broke on \"outfile\"\n", 2);
	else if (flag == -2)
		ft_putstr_fd("\"open\" broke on \"infile\"\n", 2);
	else if (flag == 3)
		ft_putstr_fd("\"dup2\" is broken, bring the next one\n", 2);
	else if (flag == 4)
		ft_putstr_fd("\"execve\" is broken, bring the next one\n", 2);
	else if (flag == 5)
		ft_putstr_fd("Malloc didn't work out in ft_strjoin\n", 2);
	else if (flag == 6)
		ft_putstr_fd("Malloc didn't work out in ft_split\n", 2);
	if (data->fd != -1)
		close (data->fd);
	ft_django_unchained(p8);
	ft_django_unchained(data->path);
	ft_django_unchained(data->command);
	exit(1);
}

int	ft_exit_without_cleaning(int flag, int argc)
{
	if (flag == 1)
	{
		if (argc < 5)
			ft_putstr_fd("Gimme, gimme (more arguments) \
			\nGimme (more arguments)\n", 2);
		else if (argc > 5)
			ft_putstr_fd("Gimme, gimme (fewer arguments) \
			\nGimme (fewer arguments)\n", 2);
	}
	else if (flag == 2)
		ft_putstr_fd("The \"pipe\" leaked\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Malloc didn 't work out in split\n", 2);
	return (1);
}
