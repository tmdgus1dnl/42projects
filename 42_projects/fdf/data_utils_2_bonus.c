/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:55:21 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:56:08 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	map_init(t_map *map)
{
	map -> x_focus = map -> x_win_size / 2;
	map -> y_focus = map -> y_win_size / 2;
	map -> x_tile = 20;
	map -> y_tile = 20;
	map -> x_angle = 0;
	map -> y_angle = 0;
	map -> z_angle = 0;
	map -> z_mux = 20;
	map -> edit_flag = 0;
	map -> y_mid = map -> y_max / 2;
	map -> x_mid = map -> x_max / 2;
	map -> red_dot_x = 0;
	map -> red_dot_y = 0;
	map -> ortho_flag = 0;
	map -> get_mid_flag = 0;
	map -> return_flag = 1;
}

static void	get_cord_y(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	map -> y_next = map -> y_start;
	while (x < map -> x_max)
	{
		y = 0;
		while (y < map -> y_max)
		{
			(map -> cord)[y][x]. z *= map -> z_mux;
			if (x == map -> x_max / 2 && y == map -> y_max / 2)
			{
				if (map -> get_mid_flag == 1)
					(map -> cord)[y][x]. z = 0;
			}
			(map -> cord)[y][x]. y_win = map -> y_next;
			map -> y_next += map -> y_tile;
			y++;
		}
		map -> y_next = map -> y_start;
		x++;
	}
}

void	get_map_cord(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map -> x_next = map -> x_start;
	while (y < map -> y_max)
	{
		x = 0;
		while (x < map -> x_max)
		{
			if (map -> return_flag == 1)
				(map -> cord)[y][x]. clean_z = (map -> cord)[y][x]. ini_z;
			(map -> cord)[y][x]. z = (map -> cord)[y][x]. clean_z;
			(map -> cord)[y][x]. x_win = map -> x_next;
			map -> x_next += map -> x_tile;
			x++;
		}
		map -> x_next = map -> x_start;
		y++;
	}
	get_cord_y(map);
}

void	put_window_image(t_map *map)
{
	int	xw_size;
	int	yw_size;
	int	bpp;
	int	s_line;
	int	end;

	xw_size = map -> x_win_size;
	yw_size = map -> y_win_size;
	map -> w_p = mlx_new_window(map -> m_p, xw_size, yw_size, "window");
	map -> i_p = mlx_new_image(map -> m_p, xw_size, yw_size);
	map -> i_p_data = (int *)mlx_get_data_addr(map -> i_p, &bpp, &s_line, &end);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> y_max)
	{
		free((map -> cord)[i]);
		i++;
	}
	free(map -> cord);
	free(map);
}
