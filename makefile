# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 10:55:02 by ricmanue          #+#    #+#              #
#    Updated: 2025/01/08 09:09:04 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft ft_printf
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client: client.o libft ft_printf
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C ft_printf clean
	
fclean: clean
	rm -f server client libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus libft ft_printf clean fclean re