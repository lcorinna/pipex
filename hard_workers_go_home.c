/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_workers_go_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:50:38 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 19:57:11 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_with_cleaning(char **path, char	**command, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Sorry, bro, I didn't find the \"", 2);
		ft_putstr_fd(command[0], 2);
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
		ft_putstr_fd("\"execve\" is broken, bring the next one\n", 2);
	ft_django_unchained(path);
	ft_django_unchained(command);
	exit(1);
}

int	ft_exit_without_cleaning(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Gimme, gimme (more arguments) \
		\nGimme (more arguments)\n", 2);
	else if (flag == 2)
		ft_putstr_fd("The \"pipe\" leaked\n", 2);
	return (0);
}
