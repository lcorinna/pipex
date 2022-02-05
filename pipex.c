/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:44:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/05 18:03:18 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	i;

	i = fork();
	if (i == 0)
	{
		printf("child %d\n", i);
		exit(1);
	}
	else
	{
		i = fork();
		if (i == 0)
		{
			printf("child %d\n", i);
			exit(1);
		}
		else
			printf("parent %d\n", i);
	}
	return (0);
}
// printf("%d\n", PIPE_BUF);