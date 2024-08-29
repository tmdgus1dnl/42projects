# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:23:04 by seunghan          #+#    #+#              #
#    Updated: 2023/12/06 13:19:26 by seunghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
	   ft_utoh.c\
	   ft_utop.c\
	   ft_utoa.c
LIBFT = libft.a
LIB_DR = ./libft
OBJS = $(SRCS:%c=%o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_DR)/$(LIBFT)
	cp $(LIB_DR)/$(LIBFT) $(NAME)
	ar rcs $@ $^

$(LIB_DR)/$(LIBFT) :
	make -C $(LIB_DR)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJS)
	make -C $(LIB_DR) clean

fclean : clean
	make fclean -C $(LIB_DR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
