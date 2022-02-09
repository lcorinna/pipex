/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 18:13:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		num;
	char	**path;
	int		pipepsi[2];

	if (argc < 5)
		return (ft_exit_for_argc(2));
	if (pipe(pipepsi))
		return (0); ///mistake
	num = 0;
	if (envp != NULL && ft_creating_a_path(envp, &num))
		path = ft_split(envp[num] + 5, ':');
	else
		path = NULL;
	pid = fork();
	if (pid == 0)
		ft_nursery_group(argv, path, pipepsi);
	else
		ft_middle_group(argv, path, pipepsi);
	return (0);
}
