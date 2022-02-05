# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 18:08:23 by lcorinna          #+#    #+#              #
#    Updated: 2022/01/30 18:12:45 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PIPEX = pipex

PIPEX = pipex.c

OBJ_PIPEX = $(PIPEX:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address # Leaks --atExit -- ./push_swap

# PATH_LIBFT = ./libft/

# LIBFT = libft.a 

all: $(NAME_PIPEX)

# libmake: 
# 	make -C $(PATH_LIBFT)
# 	@cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
$(NAME_PIPEX): $(OBJ_PIPEX)
	gcc $(CFLAGS) $(OBJ_PIPEX) -o $@

%.o: %.c pipex.h Makefile
	gcc $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ_PIPEX)
	# make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME_PIPEX)
	# make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re