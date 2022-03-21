/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:59 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/21 19:06:17 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include <string.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_data
{
	pid_t	pid;
	char	**path;
	char	**command;
	int		i;
	int		fd;
	int		pepsi[2];
}	t_data;

int		ft_django_unchained(char **arr);
int		ft_creating_a_path(char **envp, int *num);
void	ft_taking_care_of_norminette(char **path, char *str);

void	ft_nursery_group(char **argv, t_data *data, char **envp);
void	ft_middle_group(char **argv, t_data *data, char **envp);
char	**ft_adding_program_to_the_path(t_data *data, int i);

void	ft_exit_with_cleaning(t_data *data, char **p8, int flag);
int		ft_exit_without_cleaning(int flag, int argc);

#endif