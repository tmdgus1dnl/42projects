# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 17:28:08 by seunghan          #+#    #+#              #
#    Updated: 2024/07/14 12:40:43 by seunghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
SRCS = action_bonus.c\
	   chk_bonus.c\
	   forks_bonus.c\
	   data_race_bonus.c\
	   ft_atoi_bonus.c\
	   mallocs_bonus.c\
	   make_philos_bonus.c\
	   print_bonus.c\
	   time_bonus.c\
	   semaphores_bonus.c\
	   simulation_bonus.c\
	   thread_bonus.c\
	   main_bonus.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
