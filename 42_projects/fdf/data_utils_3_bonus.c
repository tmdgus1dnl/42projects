/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:54:21 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:56:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_cord_to_mid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map -> y_max)
	{
		x = 0;
		while (x < map -> x_max)
		{
			(map -> cord)[y][x]. x_win += map -> x_to_focus_true;
			(map -> cord)[y][x]. y_win += map -> y_to_focus_true;
			x++;
		}
		y++;
	}
}

void	navigate_pixel_point(t_map *map)
{
	if (map -> x_pixel_p >= map -> y_pixel_p)
		navigate_x_big(map);
	else
		navigate_y_big(map);
}

void	soft_zoom(int key_code, t_map *map)
{
	if (key_code == KEY_I)
	{
		map -> x_tile += 1;
		map -> y_tile += 1;
		map -> z_mux += 1;
	}
	if (key_code == KEY_O)
	{
		map -> x_tile -= 1;
		map -> y_tile -= 1;
		map -> z_mux -= 1;
	}
}

void	get_ini_z(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map -> y_max)
	{
		x = 0;
		while (x < map -> x_max)
		{
			(map -> cord)[y][x]. clean_z = (map -> cord)[y][x]. ini_z;
			x++;
		}
		y++;
	}
}

void	map_first_init(void *mlx_ptr, void *win_ptr, void *img_ptr, t_map *map)
{
	map -> x_win_size = 1400;
	map -> y_win_size = 1200;
	map -> x_focus = map -> x_win_size / 2;
	map -> y_focus = map -> y_win_size / 2;
	map -> x_start = 0;
	map -> y_start = 0;
	map -> x_tile = 20;
	map -> y_tile = 20;
	map -> x_angle = 0;
	map -> y_angle = 0;
	map -> z_angle = 0;
	map -> z_mux = 20;
	map -> edit_flag = 0;
	map -> w_p = win_ptr;
	map -> m_p = mlx_ptr;
	map -> i_p = img_ptr;
	map -> x_max = 0;
	map -> y_max = 0;
	map -> red_dot_x = 0;
	map -> red_dot_y = 0;
	map -> ortho_flag = 0;
	map -> get_mid_flag = 0;
}
