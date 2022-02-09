/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 19:37:11 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**path;
	int		pipepsi[2];

	if (argc < 5)
		return (ft_exit_without_cleaning(1));
	if (pipe(pipepsi))
		return (ft_exit_without_cleaning(2));
	if (envp != NULL && ft_creating_a_path(envp, &argc))
		path = ft_split(envp[argc] + 5, ':');
	else
		path = NULL;
	pid = fork();
	if (pid == 0)
		ft_nursery_group(argv, path, pipepsi);
	else
		ft_middle_group(argv, path, pipepsi);
	return (0);
}
