# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:23:04 by seunghan          #+#    #+#              #
#    Updated: 2024/03/18 15:05:09 by seunghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server\
	   client
LIBFT = libft.a
LIB_DR = ./libft

ifdef WITH_BONUS
	SERVER = server_bonus.o
	CLIENT = client_bonus.o
else
	SERVER = server.o
	CLIENT = client.o
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

server : $(SERVER) $(LIB_DR)/$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

client : $(CLIENT) $(LIB_DR)/$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DR)/$(LIBFT) :
	make bonus -C $(LIB_DR)

clean :
	make fclean -C $(LIB_DR)
	rm -rf $(SERVER) $(CLIENT) server_bonus.o client_bonus.o

fclean : clean
	rm -rf client server

re : fclean all

.PHONY : all clean fclean re
