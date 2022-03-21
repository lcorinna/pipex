/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/21 19:26:03 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_checking_arguments(t_bdata *data, int argc, char **argv, char **envp)
{
}

int	main(int argc, char **argv, char **envp)
{
	t_bdata	data;

	data.path = NULL;
	if (argc < 5)
		ft_exit(&data, 1);
	ft_checking_arguments(&data, argc, argv, envp);
	argv = NULL;
	envp = NULL;
	return (0);
}
