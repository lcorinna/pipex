/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:59 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/09 19:33:57 by lcorinna         ###   ########.fr       */
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
char	*ft_strjoin_for_pipex(char *s1, char *s2);

void	ft_nursery_group(char **argv, char **path, int *pepsi);
void	ft_middle_group(char **argv, char **path, int *pepsi);
char	**ft_adding_a_program_to_the_path(char **command, char **path, int i);

void	ft_exit_with_cleaning(char **path, char	**command, int flag);
int		ft_exit_without_cleaning(int flag);

#endif