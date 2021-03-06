/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:59 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/02 19:02:38 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include "./pipex.h"
# include <sys/wait.h>

typedef struct s_bdata
{
	int		qtt_cmd;
	int		n_cmd;
	char	**path;
	int		**pipe;
	pid_t	pid;
	int		n_child;
	int		fd;
	char	**command;
	int		i;
	char	**path2;

	char	**ar;
	char	**en;
	int		size_st;
}	t_bdata;

void	ft_making_processes(t_bdata *data, char **argv, char **envp);
void	ft_close_all_pipes(t_bdata *data);
void	ft_filling_data(t_bdata *data, int argc, char **envp);
void	ft_memory_allocation(t_bdata *data, int argc);

int		ft_creating_a_path_b(char **envp, int *num);
void	ft_django_unchained_b(char **arr);
void	ft_cleaning_memory(t_bdata *data, int flag);
void	ft_exit(t_bdata *data, int flag);
void	ft_close_exit(t_bdata *data, int flag);

void	ft_add_program_path(t_bdata *data, int i);
void	ft_cut_cmd(t_bdata *data, char **argv);
void	ft_first_entry(t_bdata *data, char **envp, char **argv);
void	ft_last_entry(t_bdata *data, char **envp, char **argv);
void	ft_routine(t_bdata *data, char **envp, char **argv);

void	ft_pipe_closure(t_bdata *data);
void	ft_taking_care_of_norminette(char **path, char *str);
void	ft_check_full_path_first(t_bdata *data, char **argv, char **envp);
void	ft_check_full_path_last(t_bdata *data, char **argv, char **envp);
void	ft_check_full_path_routine(t_bdata *data, char **argv, char **envp);

void	ft_filling_struct(t_bdata *data, char **argv, char **envp, int argc);
void	ft_read_in_pipe(t_bdata *data);
void	ft_go_to_fork(t_bdata *data, int i);
void	ft_here_doc(t_bdata *data, char **argv, char **envp, int argc);

void	ft_cut_cmd_h(t_bdata *data, int cmd);
void	ft_full_path_ptp(t_bdata *data);
void	ft_from_pipe_to_pipe(t_bdata *data);
void	ft_full_path_wtf(t_bdata *data);
void	ft_writing_to_file(t_bdata *data);

#endif 