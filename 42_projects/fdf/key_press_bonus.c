/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:02:33 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:59:32 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_press_1(int key_code, t_map *map)
{
	map -> key_flag = 1;
	if (key_code == KEY_8)
		map -> x_angle -= 5;
	else if (key_code == KEY_7)
		map -> y_angle += 5;
	else if (key_code == KEY_4)
		map -> z_angle -= 5;
	else if (key_code == KEY_2)
		map -> x_angle += 5;
	else if (key_code == KEY_3)
		map -> y_angle -= 5;
	else if (key_code == KEY_6)
		map -> z_angle += 5;
	else if (key_code == KEY_W)
		map -> y_focus -= 10;
	else if (key_code == KEY_S)
		map -> y_focus += 10;
	else if (key_code == KEY_A)
		map -> x_focus -= 10;
	else if (key_code == KEY_D)
		map -> x_focus += 10;
	else
		map -> key_flag = 0;
}

void	key_press_2(int key_code, t_map *map)
{
	map -> key_flag = 1;
	if (key_code == KEY_I)
	{
		if (map -> x_tile >= 200 || map -> y_tile >= 200)
			return ;
		else if (map -> x_tile <= 10 || map -> y_tile <= 10)
			soft_zoom(key_code, map);
		else
		{
			map -> x_tile += 2;
			map -> y_tile += 2;
			map -> z_mux += 2;
		}
	}
	else
		map -> key_flag = 0;
}

void	key_press_3(int key_code, t_map *map)
{
	map -> key_flag = 1;
	if (key_code == KEY_O)
	{
		if (map -> x_tile <= 2 || map -> y_tile <= 2)
			return ;
		else if (map -> x_tile <= 10 || map -> y_tile <= 10)
			soft_zoom(key_code, map);
		else
		{
			map -> x_tile -= 2;
			map -> y_tile -= 2;
			map -> z_mux -= 2;
		}
	}
	else
		map -> key_flag = 0;
}

void	key_press_4(int key_code, t_map *map)
{
	map -> key_flag = 1;
	if (key_code == KEY_UP || key_code == KEY_DOWN)
		map -> edit_flag = 1;
	else if (key_code == KEY_LEFT || key_code == KEY_RIGHT)
		map -> edit_flag = 1;
	else if (key_code == KEY_G && map -> edit_flag == 1)
		(map -> cord)[map -> red_dot_y][map -> red_dot_x]. clean_z += 1;
	else if (key_code == KEY_H && map -> edit_flag == 1)
		(map -> cord)[map -> red_dot_y][map -> red_dot_x]. clean_z -= 1;
	else
		map -> key_flag = 0;
}

void	key_press_5(int key_code, t_map *map)
{
	map -> key_flag = 1;
	if (key_code == KEY_1_UP)
		map -> ortho_flag = 1;
	else if (key_code == KEY_2_UP)
		map -> ortho_flag = 1;
	else if (key_code == KEY_3_UP)
		map -> ortho_flag = 1;
	else if (key_code == KEY_4_UP)
		map -> ortho_flag = 1;
	else if (key_code == KEY_5_UP)
		map -> ortho_flag = 1;
	else if (key_code == KEY_R)
		map_init(map);
	else if (key_code == KEY_ESC)
	{
		mlx_destroy_window(map -> m_p, map -> w_p);
		free_all(map);
		exit(0);
	}
	else
		map -> key_flag = 0;
}
