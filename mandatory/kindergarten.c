/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindergarten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:00:13 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 18:31:36 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 

char	**ft_adding_program_to_the_path(t_data *data, int i)
{
	char	*str;
	char	**path2;

	path2 = NULL;
	str = ft_strjoin("/", data->command[0]);
	if (str == NULL)
		ft_exit_with_cleaning(data, path2, 5);
	while (data->path != NULL && data->path[i])
		i++;
	path2 = (char **) malloc(sizeof (char *) * (i + 2));
	i = 0;
	while (data->path != NULL && data->path[i])
	{
		path2[i] = ft_strjoin(data->path[i], str);
		if (path2[i] == NULL)
			ft_exit_with_cleaning(data, path2, 5);
		i++;
	}
	path2[i++] = ft_strjoin("./", data->command[0]);
	if (path2[i - 1] == NULL)
		ft_exit_with_cleaning(data, path2, 5);
	path2[i] = NULL;
	ft_taking_care_of_norminette(data->path, str);
	return (path2);
}

void	ft_middle_group(char **argv, t_data *data, char **envp)
{
	data->i = 0;
	data->command = ft_split(argv[3], ' ');
	if (data->command == NULL)
		ft_exit_with_cleaning(data, NULL, 6);
	data->path = ft_adding_program_to_the_path(data, data->i);
	close(data->pepsi[1]);
	while (data->fd != 0 && data->path[data->i] != NULL)
		data->fd = access(data->path[data->i++], F_OK);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, 1);
	data->i--;
	data->fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, 2);
	if (dup2(data->fd, 1) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	if (dup2(data->pepsi[0], 0) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	close(data->fd);
	close(data->pepsi[0]);
	if (execve(data->path[data->i], data->command, envp) == -1)
		ft_exit_with_cleaning(data, NULL, 4);
}

void	ft_nursery_group(char **argv, t_data *data, char **envp)
{
	data->i = 0;
	data->command = ft_split(argv[2], ' ');
	if (data->command == NULL)
		ft_exit_with_cleaning(data, NULL, 6);
	data->path = ft_adding_program_to_the_path(data, data->i);
	close(data->pepsi[0]);
	while (data->fd != 0 && data->path[data->i] != NULL)
		data->fd = access(data->path[data->i++], F_OK);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, 1);
	data->i--;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		ft_exit_with_cleaning(data, NULL, -2);
	if (dup2(data->fd, 0) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	if (dup2(data->pepsi[1], 1) == -1)
		ft_exit_with_cleaning(data, NULL, 3);
	close(data->fd);
	close(data->pepsi[1]);
	if (execve(data->path[data->i], data->command, envp) == -1)
		ft_exit_with_cleaning(data, NULL, 4);
}
