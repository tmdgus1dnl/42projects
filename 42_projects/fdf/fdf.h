/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:53:10 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/21 20:08:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "keys.h"
# include "./libft/libft.h"
# define RED 0xFF0000
# define WHITE 0x00FFFFFF

typedef struct s_cord
{
	int	z;
	int	clean_z;
	int	ini_z;
	int	x_win;
	int	y_win;
}	t_cord;

typedef struct s_map
{
	int		x_max;
	int		x_win_size;
	int		red_dot_x;
	int		x_start;
	int		x_mid;
	int		x_end;
	int		x_go;
	int		x_tile;
	int		x_next;
	int		x_iter;
	int		x_trg;
	int		x_pixel_p;
	int		x_diff;
	int		x_focus;
	int		x_to_focus;
	int		x_to_focus_true;
	int		x_angle;
	int		x_win;
	int		next_x_win;
	int		y_max;
	int		y_win_size;
	int		red_dot_y;
	int		y_start;
	int		y_mid;
	int		y_end;
	int		y_go;
	int		y_tile;
	int		y_next;
	int		y_iter;
	int		y_trg;
	int		y_pixel_p;
	int		y_diff;
	int		y_focus;
	int		y_to_focus;
	int		y_to_focus_true;
	int		y_angle;
	int		y_win;
	int		next_y_win;
	int		z_angle;
	int		z_mux;
	int		div;
	int		mod;
	int		fair_db;
	int		last_db;
	int		fair_db_const;
	int		last_db_const;
	int		y_flag;
	int		up_flag;
	int		back_flag;
	int		x_0flag;
	int		y_0flag;
	int		edit_flag;
	int		ortho_flag;
	int		get_mid_flag;
	int		return_flag;
	int		key_flag;
	int		*i_p_data;
	double	sine;
	double	cosi;
	double	angle;
	void	*m_p;
	void	*w_p;
	void	*i_p;
	t_cord	**cord;
}	t_map;

void	put_window_image(t_map *map);
void	make_iso(t_map *map);
void	make_ortho(int key_code, t_map *map);
void	draw_map(int key_code, t_map *map);
void	draw_x(t_map *map);
void	draw_y(t_map *map);
void	to_target(t_map *map);
void	rotate(t_map *map);
void	get_hooks(t_map *map);
void	get_map_data(t_map *map);
void	get_map_cord(t_map *map);
void	get_diff(t_map *map);
void	map_init(t_map *map);
void	map_first_init(void *mlx_ptr, void *win_ptr, void *img_ptr, t_map *map);
void	adjust_cord(int key_code, t_map *map);
void	move_cord_to_mid(t_map *map);
void	navigate_pixel_point(t_map *map);
void	put_pixel(t_map *map);
void	navigate_x_big(t_map *map);
void	navigate_y_big(t_map *map);
void	get_target(t_map *map);
void	get_src(t_map *map);
void	get_ini_z(t_map *map);
void	free_all(t_map *map);
void	soft_zoom(int key_code, t_map *map);
void	move_red_dot(int key_code, t_map *map);
void	key_press_1(int key_code, t_map *map);
void	key_press_2(int key_code, t_map *map);
void	key_press_3(int key_code, t_map *map);
void	key_press_4(int key_code, t_map *map);
void	key_press_5(int key_code, t_map *map);
void	clear_image(t_map *map);
int		key_press_events(int key_code, t_map *map);
t_map	*get_map(char **argv, void *mlx_ptr, void *win_ptr, void *img_ptr);

#endif
