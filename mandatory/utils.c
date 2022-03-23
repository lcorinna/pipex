/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:50:38 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 18:12:39 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_taking_care_of_norminette(char **path, char *str)
{
	if (str != NULL)
		free (str);
	ft_django_unchained(path);
}

int	ft_django_unchained(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (1);
}

int	ft_creating_a_path(char **envp, int *num)
{
	int	check;

	check = 0;
	while (envp[*num] != NULL && check != 4)
		check = ft_memcmp("PATH", envp[(*num)++], 4);
	if (check != 4)
		return (0);
	(*num)++;
	return (1);
}
