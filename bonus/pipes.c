/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:33:27 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/24 16:38:31 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**ft_adding_program_path(t_data *data, int i)
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

void	ft_cut_cmd(t_bdata *data, char **argv)
{
	int	i;

	i = 0;
	data->command[0] = argv[data->n_cmd];
	while (*data->command[0])
	{
		if (*data->command[0] == '/')
			i++;
		data->command[0]++;
	}
	data->command[0] = argv[data->n_cmd];
	while (i)
	{
		if (*data->command[0] == '/')
			i--;
		data->command[0]++;
	}
}

void	ft_omg_this_full_path(t_bdata *data, char **argv, char **envp)
{
	if (access(argv[data->n_cmd][0], F_OK))
		return ;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		ft_exit(data, 5);
	if (dup2(data->fd, 0))
		ft_close_exit(data, 1);
	if (dup2(data->pipe[1], 1) == -1)
		ft_close_exit(data, 1);
	ft_cut_cmd(data, argv);
	if (execve(argv[data->n_cmd], data->command[0], envp))
		ft_close_exit(data, 2);
}

void	ft_first_entry(t_bdata *data, char **envp, char **argv)
{
	close(data->pipe[0]);
	if (argv[data->n_cmd][0] == '/')
		ft_omg_this_full_path(data, argv, envp);
	data->command = ft_split(argv[data->n_cmd], ' ');
	if (data->command == NULL)
		ft_exit(data, 6);

	data->path = ft_adding_program_path(data, data->i);

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
		
	if (execve(data->path[data->i], data->command, envp) == -1)
		ft_exit_with_cleaning(data, NULL, 4);
}