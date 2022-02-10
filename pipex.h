/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:59 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/10 17:16:12 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include <string.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>

void	ft_django_unchained(char **arr);
int		ft_creating_a_path(char **envp, int *num);
void	ft__taking_care_of_norminette(char **path, char *str);

void	ft_nursery_group(char **argv, char **path, int *pepsi, char **envp);
void	ft_middle_group(char **argv, char **path, int *pepsi, char **envp);
char	**ft_adding_a_program_to_the_path(char **command, char **path, int i);

void	ft_exit_with_cleaning(char **path, char **p8, char **command, int flag);
int		ft_exit_without_cleaning(int flag, int argc);

#endif