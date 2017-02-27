# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 10:13:22 by tmaurin           #+#    #+#              #
#    Updated: 2016/04/19 13:13:35 by opettex-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror

HEADERS 	= ./includes/
SRC			= ./ft_memset.c \
			  ./ft_bzero.c \
			  ./ft_memcpy.c \
			  ./ft_memccpy.c \
			  ./ft_memmove.c \
			  ./ft_memchr.c \
			  ./ft_memcmp.c  \
			  ./ft_strlen.c \
			  ./ft_strdup.c \
			  ./ft_strcpy.c \
			  ./ft_strncpy.c \
			  ./ft_strcat.c \
			  ./ft_strncat.c \
			  ./ft_strchr.c \
			  ./ft_strrchr.c \
			  ./ft_strstr.c \
			  ./ft_strnstr.c \
			  ./ft_strcmp.c \
			  ./ft_strncmp.c \
			  ./ft_atoi.c \
			  ./ft_isalpha.c \
			  ./ft_isdigit.c \
			  ./ft_isalnum.c \
			  ./ft_isascii.c \
			  ./ft_isprint.c \
			  ./ft_toupper.c \
			  ./ft_tolower.c \
			  ./ft_memalloc.c \
			  ./ft_memdel.c \
			  ./ft_strnew.c \
			  ./ft_strdel.c \
			  ./ft_strclr.c \
			  ./ft_striter.c \
			  ./ft_striteri.c \
			  ./ft_strmap.c \
			  ./ft_strmapi.c \
			  ./ft_strequ.c \
			  ./ft_strnequ.c \
			  ./ft_strsub.c \
			  ./ft_strjoin.c \
			  ./ft_strtrim.c \
			  ./ft_strsplit.c \
			  ./ft_itoa.c \
			  ./ft_putchar.c \
			  ./ft_putstr.c \
			  ./ft_putendl.c \
			  ./ft_putnbr.c \
			  ./ft_putstr_fd.c \
			  ./ft_putendl_fd.c \
			  ./ft_putnbr_fd.c \
			  ./ft_putchar_fd.c \
			  ./ft_strlcat.c \
			  ./ft_lstnew.c \
			  ./ft_lstadd.c \
			  ./ft_lstiter.c \
			  ./ft_lstdel.c \
			  ./ft_lstdelone.c \
			  ./ft_strrevchr.c \
			  ./ft_memmove_malloc.c \
			  ./ft_lstmap.c \
			  ./get_next_line.c


OBJ			= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(MAIN)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(TEST)

re: fclean all
