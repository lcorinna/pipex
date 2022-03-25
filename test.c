/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:14:08 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/25 15:33:27 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int	input(int	**matrix, int *n, int *m)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	scanf("%d %d", n, m);
// 	printf("n - %d\n", *n);
// 	printf("m - %d\n", *m);
// 	matrix = malloc(sizeof(int *) * *n);
// 	while (i < *n)
// 		matrix[i++] = malloc(sizeof(int) * *m);
// 	i = -1;
// 	j = 0;
// 	while (++i < *n)
// 	{
// 		// printf("i - %d\n", i);
// 		while (j < *m)
// 		{
// 			scanf("%d", &matrix[i][j++]);
// 			// printf("matrix[i][j++] - %d\n", matrix[i][j++]);
// 		}
// 	}
// 	i = 0;
// 	j = 0;
// 	while (i < *n)
// 	{
// 		printf("i - %d\n", i);
// 		while (j < *m)
// 		{
// 			printf("matrix[%d][%d] - %d\n", i, j, matrix[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	// int		**matrix;
	// int		n;
	// int		m;
	// int		res;

	// matrix = NULL;
	// res = input(matrix, &n, &m);
	printf("%d\n", argc);
	argv = NULL;
	return (0);
}
