/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 18:29:38 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_adding_struct(t_data *data, int argc)
{
	data->path = NULL;
	data->command = NULL;
	data->fd = -1;
	if (argc != 5)
		return (ft_exit_without_cleaning(1, argc));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (ft_adding_struct(&data, argc))
		return (1);
	if (pipe(data.pepsi))
		return (ft_exit_without_cleaning(2, argc));
	argc = 0;
	if (envp != NULL && ft_creating_a_path(envp, &argc))
	{
		data.path = ft_split(envp[argc] + 5, ':');
		if (data.path == NULL)
			return (ft_exit_without_cleaning(3, argc));
	}
	data.pid = fork();
	if (data.pid == -1)
	{
		ft_putstr_fd("fork error\n", 2);
		return (ft_django_unchained(data.path));
	}
	if (data.pid == 0)
		ft_nursery_group(argv, &data, envp);
	else
		ft_middle_group(argv, &data, envp);
	return (0);
}
