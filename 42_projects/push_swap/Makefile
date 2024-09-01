# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:23:04 by seunghan          #+#    #+#              #
#    Updated: 2024/03/10 17:18:26 by seunghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MA_O = push_swap.o
B_MA_O = checker_bonus.o
TARG = push_swap
B_TARG = checker
SRCS = error_chk.c\
	   make_lst.c\
	   cmd_set.c\
	   sort_a.c\
	   sort_b.c\
	   data_utils.c\
	   data_utils_2.c\
	   data_utils_3.c\
	   small_sort.c\
	   print_cmd.c
B_SRCS = get_next_line_bonus.c\
	   get_next_line_utils_bonus.c
LIBFT = libft.a
LIB_DR = ./libft
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(B_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(OBJECTS_BONUS) $(B_MA_O)
	NAME = $(B_TARG)
else
	OBJS = $(OBJECTS) $(MA_O)
	NAME = $(TARG)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME) : $(OBJS) $(LIB_DR)/$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIB_DR)/$(LIBFT) :
	make bonus -C $(LIB_DR)

clean :
	rm -rf $(OBJECTS) $(OBJECTS_BONUS) $(MA_O) $(B_MA_O)
	make -C $(LIB_DR) clean

fclean : clean
	make fclean -C $(LIB_DR)
	rm -rf $(TARG) $(B_TARG)

re : fclean all

.PHONY : all clean fclean re
