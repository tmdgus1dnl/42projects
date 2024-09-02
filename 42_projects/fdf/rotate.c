/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_temp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:47:46 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/05 21:11:51 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_map *map, double rad_angle)
{
	double	y;
	double	y_temp;
	double	z;

	y = (map -> cord)[map -> y_iter][map -> x_iter]. y_win;
	z = (map -> cord)[map -> y_iter][map -> x_iter]. z;
	y_temp = y * cos(rad_angle) + z * sin(rad_angle);
	z = -y * sin(rad_angle) + z * cos(rad_angle);
	(map -> cord)[map -> y_iter][map -> x_iter]. y_win = (int)(round(y_temp));
	(map -> cord)[map -> y_iter][map -> x_iter]. z = (int)(round(z));
}

static void	rotate_y(t_map *map, double rad_angle)
{
	double	x;
	double	x_temp;
	double	z;

	x = (map -> cord)[map -> y_iter][map -> x_iter]. x_win;
	z = (map -> cord)[map -> y_iter][map -> x_iter]. z;
	x_temp = x * cos(rad_angle) - z * sin(rad_angle);
	z = x * sin(rad_angle) + z * cos(rad_angle);
	(map -> cord)[map -> y_iter][map -> x_iter]. x_win = (int)(round(x_temp));
	(map -> cord)[map -> y_iter][map -> x_iter]. z = (int)(round(z));
}

static void	rotate_z(t_map *map, double rad_angle)
{
	double	x;
	double	x_temp;
	double	y;

	x = (map -> cord)[map -> y_iter][map -> x_iter]. x_win;
	y = (map -> cord)[map -> y_iter][map -> x_iter]. y_win;
	x_temp = x * cos(rad_angle) + y * sin(rad_angle);
	y = -x * sin(rad_angle) + y * cos(rad_angle);
	(map -> cord)[map -> y_iter][map -> x_iter]. x_win = (int)(round(x_temp));
	(map -> cord)[map -> y_iter][map -> x_iter]. y_win = (int)(round(y));
}

void	rotate(t_map *map)
{
	double	rad_angle;

	if (map -> x_angle == 360 || map -> x_angle == -360)
		map -> x_angle = 0;
	if (map -> y_angle == 360 || map -> y_angle == -360)
		map -> y_angle = 0;
	if (map -> z_angle == 360 || map -> z_angle == -360)
		map -> z_angle = 0;
	if (map -> x_angle)
	{
		rad_angle = (map -> x_angle) * M_PI / 180;
		rotate_x(map, rad_angle);
	}
	if (map -> y_angle)
	{
		rad_angle = (map -> y_angle) * M_PI / 180;
		rotate_y(map, rad_angle);
	}
	if (map -> z_angle)
	{
		rad_angle = (map -> z_angle) * M_PI / 180;
		rotate_z(map, rad_angle);
	}
}
