/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:14 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.fd = -1;
	data.path = NULL;
	data.command = NULL;
	if (argc != 5)
		return (ft_exit_without_cleaning(1, argc));
	if (pipe(data.pepsi))
		return (ft_exit_without_cleaning(2, argc));
	if (envp != NULL && ft_creating_a_path(envp, &argc))
	{
		data.path = ft_split(envp[argc] + 5, ':');
		if (data.path == NULL)
			return (ft_exit_without_cleaning(3, argc));
	}
	else
		data.path = NULL;
	data.pid = fork();
	if (data.pid == -1)
		return (ft_django_unchained(data.path));
	if (data.pid == 0)
		ft_nursery_group(argv, &data, envp);
	else
		ft_middle_group(argv, &data, envp);
	return (0);
}
