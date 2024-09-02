/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:16:23 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/07 20:46:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_iso(t_map *map)
{
	double	x;
	double	x_temp;
	double	y;
	double	z;
	double	iso_angle;

	iso_angle = 30 * M_PI / 180;
	x = (map -> cord)[map -> y_iter][map -> x_iter]. x_win;
	y = (map -> cord)[map -> y_iter][map -> x_iter]. y_win;
	z = (map -> cord)[map -> y_iter][map -> x_iter]. z;
	x_temp = (x - y) * cos(iso_angle);
	y = (x + y) * sin(iso_angle) - z;
	if (map -> x_iter == map -> x_max / 2 && map -> y_iter == map -> y_max / 2)
	{
		map -> x_to_focus = map -> x_focus - x_temp;
		map -> y_to_focus = map -> y_focus - y;
	}
	(map -> cord)[map -> y_iter][map -> x_iter]. x_win = (int)(round(x_temp));
	(map -> cord)[map -> y_iter][map -> x_iter]. y_win = (int)(round(y));
}

void	make_ortho(int key_code, t_map *map)
{
	map -> x_angle = 0;
	map -> y_angle = 0;
	if (key_code == KEY_1_UP)
		map -> x_angle += 90;
	else if (key_code == KEY_2_UP)
		map -> x_angle -= 90;
	else if (key_code == KEY_3_UP)
		map -> y_angle += 90;
	else if (key_code == KEY_4_UP)
		map -> y_angle -= 90;
}
