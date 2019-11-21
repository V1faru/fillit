# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:23:10 by jwilen            #+#    #+#              #
#    Updated: 2019/11/21 12:06:28 by amurtone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = srcs/grid.c srcs/main.c srcs/parse.c srcs/validator.c srcs/solver.c \
		srcs/solve_helper.c
OBJ = $(subst .c,.o,$(SRCS))
HEADER = ./includes/fillit.h
FLAGS = -Wall -Wextra -Werror

LIBFT = includes/libft/

all: $(NAME)

$(NAME): 
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. includes/libft/libft.a

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
