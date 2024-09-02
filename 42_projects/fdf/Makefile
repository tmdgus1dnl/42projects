# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:23:04 by seunghan          #+#    #+#              #
#    Updated: 2024/06/11 17:32:22 by seunghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
TARG = fdf
SRCS = fdf.c\
	   make_projtions.c\
	   hooks.c\
	   to_target.c\
	   to_target_utils.c\
	   data_utils.c\
	   data_utils_2.c\
	   data_utils_3.c\
	   data_utils_4.c\
	   draw_map.c\
	   key_press.c\
	   edit_terrain.c\
	   rotate.c\
	   ./get_next_line/get_next_line.c\
	   ./get_next_line/get_next_line_utils.c
B_SRCS = fdf_bonus.c\
	   make_projtions_bonus.c\
	   hooks_bonus.c\
	   to_target_bonus.c\
	   to_target_utils_bonus.c\
	   data_utils_bonus.c\
	   data_utils_2_bonus.c\
	   data_utils_3_bonus.c\
	   data_utils_4_bonus.c\
	   draw_map_bonus.c\
	   key_press_bonus.c\
	   edit_terrain_bonus.c\
	   rotate_bonus.c\
	   ./get_next_line/get_next_line_bonus.c\
	   ./get_next_line/get_next_line_utils_bonus.c
LIBFT = libft.a
LIB_DR = ./libft
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(B_SRCS:.c=.o)
MLX_DR = /usr/local/include

ifdef WITH_BONUS
	OBJS = $(OBJECTS_BONUS)
	NAME = $(TARG)
else
	OBJS = $(OBJECTS)
	NAME = $(TARG)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME) : $(OBJS) $(LIB_DR)/$(LIBFT)
	$(CC) $(OBJS) $(LIB_DR)/$(LIBFT) -L$(MLX_DR) -lmlx -framework OpenGL -framework AppKit -lz -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DR)/$(LIBFT) :
	make bonus -C $(LIB_DR)

clean :
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	make fclean -C $(LIB_DR)

fclean : clean
	rm -rf $(TARG)

re : fclean all

.PHONY : all clean fclean re
