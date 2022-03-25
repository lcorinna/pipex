# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 18:08:23 by lcorinna          #+#    #+#              #
#    Updated: 2022/03/25 17:18:52 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PIPEX = pipex

PIPEX = ./mandatory/pipex.c ./mandatory/utils.c ./mandatory/kindergarten.c \
./mandatory/hard_workers_go_home.c

PIPEX_B = ./bonus/pipex_bonus.c ./bonus/pipex_utils.c ./mandatory/utils.c \
./bonus/pipes.c ./bonus/pipes_second.c

OBJ_PIPEX = $(PIPEX:.c=.o)

OBJ_PIPEX_B = $(PIPEX_B:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g #Leaks --atExit -- ./pipex

PATH_LIBFT = ./libft/

LIBFT = libft.a

override ALL_O_FILES ?= $(OBJ_PIPEX)

all: libmake $(NAME_PIPEX)

libmake:
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
$(NAME_PIPEX): $(ALL_O_FILES)
	cc $(CFLAGS) $(LIBFT) $(ALL_O_FILES) -o $@

%.o: %.c pipex.h pipex_bonus.h Makefile
	cc $(CFLAGS) -c $< -o $@

bonus: #fclean
	make ALL_O_FILES="$(OBJ_PIPEX_B)" all

clean:
	rm -f $(OBJ_PIPEX) $(OBJ_PIPEX_B) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME_PIPEX)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all libmake bonus clean fclean re