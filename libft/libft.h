/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:40:44 by lcorinna          #+#    #+#             */
/*   Updated: 2022/04/01 19:21:25 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/cdefs.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *r);
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen_gnl(char *r);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_trim_for_str(char *res);
char	*ft_trim_for_res(char *res);
char	*ft_read(int fd, char *res, int *chit, int i);
char	*get_next_line(int fd);
char	*ft_res_res(char *res, int i);
char	*ft_free_res(char *res, int *chit);

#endif