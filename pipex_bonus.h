/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:59 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/23 19:14:58 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include "./pipex.h"

typedef struct s_bdata
{
	char	**path;
	int		**pipe;
	char	**cmd;
	int		quantity_cmd;
	pid_t	pid;

}	t_bdata;

void	ft_exit(t_bdata *data, int flag);

#endif