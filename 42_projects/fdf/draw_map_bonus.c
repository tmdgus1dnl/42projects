/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:23:38 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:57:30 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_x(t_map *map)
{
	map -> y_flag = 0;
	map -> y_iter = 0;
	map -> x_go = (map -> cord)[0][0]. x_win;
	map -> y_go = (map -> cord)[0][0]. y_win;
	while (map -> y_iter < map -> y_max)
	{
		map -> x_iter = 0;
		while (map -> x_iter < map -> x_max - 1)
		{
			to_target(map);
			map -> x_iter++;
		}
		if (map -> y_iter != map -> y_max - 1)
		{
			map -> x_go = (map -> cord)[map -> y_iter + 1][0]. x_win;
			map -> y_go = (map -> cord)[map -> y_iter + 1][0]. y_win;
		}
		map -> y_iter++;
	}
}

void	draw_y(t_map *map)
{
	map -> y_flag = 1;
	map -> x_iter = 0;
	map -> x_go = (map -> cord)[0][0]. x_win;
	map -> y_go = (map -> cord)[0][0]. y_win;
	while (map -> x_iter < map -> x_max)
	{
		map -> y_iter = 0;
		while (map -> y_iter < map -> y_max - 1)
		{
			to_target(map);
			map -> y_iter++;
		}
		if (map -> x_iter != map -> x_max - 1)
		{
			map -> x_go = (map -> cord)[0][map -> x_iter + 1]. x_win;
			map -> y_go = (map -> cord)[0][map -> x_iter + 1]. y_win;
		}
		map -> x_iter++;
	}
}

void	draw_map(int key_code, t_map *map)
{
	draw_x(map);
	draw_y(map);
	if (map -> edit_flag == 1)
		move_red_dot(key_code, map);
	map -> return_flag = 0;
}
