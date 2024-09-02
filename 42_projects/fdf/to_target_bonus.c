/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:59:59 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	navigate_x_big(t_map *map)
{
	while (map -> x_pixel_p)
	{
		put_pixel(map);
		if (!(map -> back_flag))
			map -> x_go++;
		else if (map -> x_0flag)
			map -> x_go = map -> x_go;
		else
			map -> x_go--;
		map -> x_pixel_p--;
	}
	while (map -> y_pixel_p)
	{
		if (map -> up_flag)
			map -> y_go--;
		else if (map -> y_0flag)
			map -> y_go = map -> y_go;
		else
			map -> y_go++;
		map -> y_pixel_p--;
	}
}

void	navigate_y_big(t_map *map)
{
	while (map -> y_pixel_p)
	{
		put_pixel(map);
		if (map -> up_flag)
			map -> y_go--;
		else if (map -> y_0flag)
			map -> y_go = map -> y_go;
		else
			map -> y_go++;
		map -> y_pixel_p--;
	}
	while (map -> x_pixel_p)
	{
		if (!(map -> back_flag))
			map -> x_go++;
		else if (map -> x_0flag)
			map -> x_go = map -> x_go;
		else
			map -> x_go--;
		map -> x_pixel_p--;
	}
}

static void	is_x_big(t_map *map, int x, int y)
{
	while (y < map -> y_trg)
	{
		x += map -> div;
		map -> x_pixel_p += map -> div;
		if (map -> mod > 0 && map -> fair_db == y)
		{
			x++;
			map -> x_pixel_p++;
			map -> mod--;
		}
		if (map -> mod > 0 && y == map -> last_db && map -> last_db != 0)
		{
			x++;
			map -> x_pixel_p++;
			map -> last_db += map -> last_db_const;
			map -> mod--;
		}
		if (map -> fair_db <= y)
			map -> fair_db += map -> fair_db_const;
		if (map -> mod && y == map -> y_trg - 1)
			map -> x_pixel_p += map -> x_trg - x;
		y++;
		map -> y_pixel_p++;
		navigate_pixel_point(map);
	}
}

static void	is_y_big(t_map *map, int x, int y)
{
	while (x < map -> x_trg)
	{
		y += map -> div;
		map -> y_pixel_p += map -> div;
		if (map -> mod > 0 && map -> fair_db == x)
		{
			y++;
			map -> y_pixel_p++;
			map -> mod--;
		}
		if (map -> mod > 0 && x == map -> last_db && map -> last_db != 0)
		{
			y++;
			map -> y_pixel_p++;
			map -> last_db += map -> last_db_const;
			map -> mod--;
		}
		if (map -> fair_db <= x)
			map -> fair_db += map -> fair_db_const;
		if (map -> mod && x == map -> x_trg - 1)
			map -> y_pixel_p += map -> y_trg - y;
		x++;
		map -> x_pixel_p++;
		navigate_pixel_point(map);
	}
}

void	to_target(t_map *map)
{
	int	x;
	int	y;

	get_target(map);
	get_src(map);
	map -> x_pixel_p = 0;
	map -> y_pixel_p = 0;
	map -> fair_db_const = map -> fair_db;
	map -> last_db_const = map -> last_db;
	x = 0;
	y = 0;
	if (map -> x_trg >= map -> y_trg)
		is_x_big(map, x, y);
	else
		is_y_big(map, x, y);
}
