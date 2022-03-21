# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 18:08:23 by lcorinna          #+#    #+#              #
#    Updated: 2022/03/21 16:50:45 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PIPEX = pipex

PIPEX = ./mandatory/pipex.c ./mandatory/utils.c ./mandatory/kindergarten.c \
./mandatory/hard_workers_go_home.c

OBJ_PIPEX = $(PIPEX:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g #Leaks --atExit -- ./pipex "ls -la"

PATH_LIBFT = ./libft/

LIBFT = libft.a 

all: libmake $(NAME_PIPEX)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
$(NAME_PIPEX): $(OBJ_PIPEX)
	gcc $(CFLAGS) $(LIBFT) $(OBJ_PIPEX) -o $@

%.o: %.c pipex.h Makefile
	gcc $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ_PIPEX) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME_PIPEX)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all libmake clean fclean re