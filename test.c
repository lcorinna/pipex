/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:14:08 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/24 12:49:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argv[2][0] == '/')
		printf("1 argv %s\n", argv[2]);
	else
		printf("2 argv %s\n", argv[2]);
	str = argv[2];
	argc = 0;
	while (*str)
	{
		if (*str == '/')
			argc++;
		str++;
	}
	printf("1 argc %d\n", argc);
	str = argv[2];
	while (argc)
	{
		if (*str == '/')
			argc--;
		str++;
	}
	printf("2 str %s\n", str);
	printf("2 argc %d\n", argc);
	return (0);
}
