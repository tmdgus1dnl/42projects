/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:11:21 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:59:23 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_press_events(int key_code, t_map *map)
{
	key_press_1(key_code, map);
	if (!map -> key_flag)
		key_press_2(key_code, map);
	if (!map -> key_flag)
		key_press_3(key_code, map);
	if (!map -> key_flag)
		key_press_4(key_code, map);
	if (!map -> key_flag)
		key_press_5(key_code, map);
	if (!map -> key_flag)
		return (0);
	adjust_cord(key_code, map);
	draw_map(key_code, map);
	mlx_put_image_to_window(map -> m_p, map -> w_p, map -> i_p, 0, 0);
	return (0);
}

static int	close_window_x(t_map *map)
{
	mlx_destroy_window(map -> m_p, map -> w_p);
	free_all(map);
	exit(0);
}

void	get_hooks(t_map *map)
{
	mlx_hook(map -> w_p, 17, 0, close_window_x, map);
	mlx_hook(map -> w_p, KEY_PRESS, 0, key_press_events, map);
}
