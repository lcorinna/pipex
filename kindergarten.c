/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindergarten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:00:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 18:58:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_adding_a_program_to_the_path(char **command, char **path, int i)
{
	char	*str;
	char	**path2;

	str = ft_strjoin("/", command[0]);
	while (path != NULL && path[i])
		i++;
	path2 = (char **) malloc(sizeof (char *) * (i + 2));
	i = 0;
	while (path != NULL && path[i])
	{
		path2[i] = ft_strjoin(path[i], str);
		i++;
	}
	path2[i++] = ft_strjoin("./", command[0]);
	path2[i] = NULL;
	free(str);
	ft_django_unchained(path);
	return (path2);
}

void	ft_middle_group(char **argv, char **path, int *pepsi)
{
	int		i;
	int		fd;
	char	**command;
	int		check;

	i = 0;
	command = ft_split(argv[3], ' ');
	path = ft_adding_a_program_to_the_path(command, path, i);
	check = -1;
	close(pepsi[1]);
	while (check != 0 && path[i] != NULL)
		check = access(path[i++], F_OK);
	if (check == -1)
		ft_exit_for_check(path, command, 1);
	i--;
	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit_for_check(path, command, 2);
	if (dup2(fd, 1) == -1)
		ft_exit_for_check(path, command, 3);
	if (dup2(pepsi[0], 0) == -1)
		ft_exit_for_check(path, command, 3);
	if (execve(path[i], command, NULL) == -1)
		ft_exit_for_check(path, command, 4);
}

void	ft_nursery_group(char **argv, char **path, int *pepsi)
{
	int		i;
	int		fd;
	char	**command;
	int		check;

	i = 0;
	command = ft_split(argv[2], ' ');
	path = ft_adding_a_program_to_the_path(command, path, i);
	check = -1;
	close(pepsi[0]);
	while (check != 0 && path[i] != NULL)
		check = access(path[i++], F_OK);
	if (check == -1)
		ft_exit_for_check(path, command, 1);
	i--;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_for_check(path, command, -2);
	if (dup2(fd, 0) == -1)
		ft_exit_for_check(path, command, 3);
	if (dup2(pepsi[1], 1) == -1)
		ft_exit_for_check(path, command, 3);
	if (execve(path[i], command, NULL) == -1)
		ft_exit_for_check(path, command, 4);
}
