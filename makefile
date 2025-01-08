# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 14:10:46 by ricmanue          #+#    #+#              #
#    Updated: 2025/01/08 15:31:49 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
SERVER					= server
CLIENT					= client

# Directories
LIBFT					= ./libft/libft.a

# Compiler and CFLAGS
CC						= @cc
CFLAGS					= -Wall -Wextra -Werror
RM						= @rm -f

# Source Files
SERVER_SRC				= server.c
CLIENT_SRC				= client.c

# Object Files
SERVER_OBJ				= server.o
CLIENT_OBJ				= client.o

# Rules
all:					$(CLIENT) $(SERVER)

$(LIBFT):
						@make -s -C ./libft

$(SERVER):				$(SERVER_OBJ) $(LIBFT)
							@echo "Building $(SERVER)..."
							$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
							@echo "$(SERVER) has been successfully built"

$(CLIENT):				$(CLIENT_OBJ) $(LIBFT)
							@echo "Building $(CLIENT)..."
							$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
							@echo "$(CLIENT) has been successfully built"

$(SERVER_OBJ):			$(SERVER_SRC)
							@echo "Compiling $(SERVER_SRC)..."
							$(CC) $(CFLAGS) -c $(SERVER_SRC) -o $(SERVER_OBJ)

$(CLIENT_OBJ):			$(CLIENT_SRC)
							@echo "Compiling $(CLIENT_SRC)..."
							$(CC) $(CFLAGS) -c $(CLIENT_SRC) -o $(CLIENT_OBJ)

clean:
						$(RM) -r $(SERVER_OBJ) $(CLIENT_OBJ)
							@make -s clean -C ./libft
							@echo "Cleaned up .o files."

fclean:					clean
							@$(RM) $(CLIENT) $(SERVER)
							@make -s fclean -C ./libft
							@echo "Removed executables."

re:						fclean all
							@echo "Fully rebuilt"

.PHONY:	all clean fclean re
