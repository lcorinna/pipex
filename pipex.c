/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/10 17:16:20 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**path;
	int		pipepsi[2];

	if (argc < 5 || argc > 5)
		return (ft_exit_without_cleaning(1, argc));
	if (pipe(pipepsi))
		return (ft_exit_without_cleaning(2, argc));
	if (envp != NULL && ft_creating_a_path(envp, &argc))
	{
		path = ft_split(envp[argc] + 5, ':');
		if (path == NULL)
			return (ft_exit_without_cleaning(3, argc));
	}
	else
		path = NULL;
	pid = fork();
	if (pid == 0)
		ft_nursery_group(argv, path, pipepsi, envp);
	else
		ft_middle_group(argv, path, pipepsi, envp);
	return (0);
}
