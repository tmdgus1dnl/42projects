/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:55:57 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:57:38 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	put_red_dot(t_map *map)
{
	int	x;
	int	y;

	x = (map -> cord)[map -> y_mid][map -> x_mid]. x_win;
	y = (map -> cord)[map -> y_mid][map -> x_mid]. y_win;
	map -> red_dot_x = map -> x_mid;
	map -> red_dot_y = map -> y_mid;
	if ((x > 0 && y > 0) && (x < map -> x_win_size && y < map -> y_win_size))
	{
		map -> i_p_data[y * map -> x_win_size + x] = RED;
		map -> i_p_data[y * map -> x_win_size + (x - 1)] = RED;
		map -> i_p_data[(y - 1) * map -> x_win_size + x] = RED;
		map -> i_p_data[y * map -> x_win_size + (x + 1)] = RED;
		map -> i_p_data[(y + 1) * map -> x_win_size + x] = RED;
		map -> i_p_data[(y + 1) * map -> x_win_size + (x + 1)] = RED;
		map -> i_p_data[(y - 1) * map -> x_win_size + (x - 1)] = RED;
		map -> i_p_data[(y + 1) * map -> x_win_size + (x - 1)] = RED;
		map -> i_p_data[(y - 1) * map -> x_win_size + (x + 1)] = RED;
		map -> i_p_data[(y + 2) * map -> x_win_size + x] = RED;
		map -> i_p_data[y * map -> x_win_size + (x + 2)] = RED;
		map -> i_p_data[(y - 2) * map -> x_win_size + x] = RED;
		map -> i_p_data[y * map -> x_win_size + (x - 2)] = RED;
	}
}

void	move_red_dot(int key_code, t_map *map)
{
	if (key_code == KEY_UP && map -> y_mid >= 1)
		map -> y_mid--;
	if (key_code == KEY_DOWN && map -> y_mid < map -> y_max - 1)
		map -> y_mid++;
	if (key_code == KEY_LEFT && map -> x_mid >= 1)
		map -> x_mid--;
	if (key_code == KEY_RIGHT && map -> x_mid < map -> x_max - 1)
		map -> x_mid++;
	put_red_dot(map);
}
