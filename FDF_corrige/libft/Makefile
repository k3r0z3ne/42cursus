# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:35:56 by arotondo          #+#    #+#              #
#    Updated: 2024/09/03 18:14:21 by arotondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c get_next_line.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_HEADER = libft.h
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(SRC_HEADER) -c $(SRC_FILES) -fPIC
	ar -rcs $(NAME) $(OBJ_FILES)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re