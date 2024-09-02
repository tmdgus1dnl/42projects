/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:36:51 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:58:23 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_map *map)
{
	int	x;
	int	y;

	x = map -> x_go;
	if (map -> x_go <= 0 || map -> x_go >= map -> x_win_size)
	{
		x = 0;
		y = 0;
	}
	y = map -> y_go;
	if (map -> y_go <= 0 || map -> y_go >= map -> y_win_size)
	{
		x = 0;
		y = 0;
	}
	if (x > 0 && y > 0)
		map -> i_p_data[y * map -> x_win_size + x] = WHITE;
}

void	clear_image(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> x_win_size * map -> y_win_size)
	{
		map -> i_p_data[i] = 0x000000;
		i++;
	}
}
