# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wollio <wollio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 15:57:03 by wollio            #+#    #+#              #
#    Updated: 2021/06/25 17:14:54 by wollio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

INCLUDES = libft.h

NAME = libft.a

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
