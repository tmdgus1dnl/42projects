/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:51:50 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 15:58:00 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_mid(int key_code, t_map *map)
{
	map -> get_mid_flag = 1;
	get_map_cord(map);
	map -> x_iter = map -> x_max / 2;
	map -> y_iter = map -> y_max / 2;
	rotate(map);
	if (!map -> ortho_flag)
		make_iso(map);
	else
		make_ortho(key_code, map);
	map -> x_to_focus_true = map -> x_to_focus;
	map -> y_to_focus_true = map -> y_to_focus;
}

void	adjust_cord(int key_code, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	clear_image(map);
	get_mid(key_code, map);
	map -> get_mid_flag = 0;
	get_map_cord(map);
	while (y < map -> y_max)
	{
		map -> y_iter = y;
		x = 0;
		while (x < map -> x_max)
		{
			map -> x_iter = x;
			rotate(map);
			if (!map -> ortho_flag)
				make_iso(map);
			else
				make_ortho(key_code, map);
			x++;
		}
		y++;
	}
	move_cord_to_mid(map);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_map	*map;

	if (argc != 2)
		return (1);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = 0;
	img_ptr = 0;
	map = get_map(argv, mlx_ptr, win_ptr, img_ptr);
	put_window_image(map);
	get_hooks(map);
	adjust_cord(0, map);
	draw_map(0, map);
	mlx_put_image_to_window(map -> m_p, map -> w_p, map -> i_p, 0, 0);
	mlx_loop(map -> m_p);
	return (0);
}
