# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 08:50:12 by jwilen            #+#    #+#              #
#    Updated: 2019/11/14 07:45:40 by jwilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_memset.c ft_strlcat.c ft_bzero.c ft_putchar.c ft_strlen.c \
	  ft_countwords.c ft_putchar_fd.c ft_strmap.c ft_getintlen.c ft_putendl.c \
	  ft_strmapi.c ft_isalnum.c ft_putendl_fd.c ft_strncat.c ft_isalpha.c \
	  ft_putnbr.c ft_strncmp.c ft_isascii.c ft_putnbr_fd.c ft_strncpy.c \
	  ft_isdigit.c ft_putstr.c ft_strnequ.c ft_islower.c ft_putstr_fd.c \
	  ft_strnew.c ft_isprint.c ft_strcat.c ft_strnstr.c ft_istherewhitespaces.c \
	  ft_strchr.c ft_strrchr.c ft_isupper.c ft_strclr.c ft_strsplit.c ft_itoa.c \
	  ft_strcmp.c ft_strstr.c ft_memalloc.c ft_strcpy.c ft_strsub.c ft_memccpy.c \
	  ft_strdel.c ft_strtrim.c ft_memchr.c ft_strdup.c ft_tolower.c ft_memcmp.c \
	  ft_strequ.c ft_toupper.c ft_memcpy.c ft_striter.c ft_wordlength.c \
	  ft_memdel.c ft_striteri.c ft_memmove.c ft_strjoin.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  get_next_line.c

OBJ = $(subst .c,.o,$(SRCS))

CC = gcc

LINKERFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(LINKERFLAG) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
