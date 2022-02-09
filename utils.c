/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:50:38 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 18:16:41 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_django_unchained(char **arr)
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

// char	*ft_strjoin_for_pipex(char *s1, char *s2)
// {
// 	int		i;
// 	int		p;
// 	char	*join;

// 	p = 0;
// 	i = 0;
// 	join = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (join == NULL)
// 		return (NULL);
// 	while (s1[i])
// 		join[p++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		join[p++] = s2[i++];
// 	join[p] = '\0';
// 	free(s1);
// 	printf("str --------> %d\n", i);
// 	return (join);
// }
