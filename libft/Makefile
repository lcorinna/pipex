# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 21:27:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/04/01 19:19:01 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST_1 = ft_strlen.c ft_substr.c ft_split.c ft_strjoin.c ft_memcmp.c \
ft_putstr_fd.c get_next_line_bonus.c get_next_line_utils_bonus.c

O_FILES = $(LIST_1:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	ar rcs $(NAME) $?

%.o: %.c libft.h Makefile
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re