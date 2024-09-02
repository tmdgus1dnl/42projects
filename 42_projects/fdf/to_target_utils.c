/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_target_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:12:43 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/13 20:57:38 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	special_case(t_map *map)
{
	int	last_db_mod;
	int	l_num;
	int	s_num;

	if (map -> x_trg >= map -> y_trg)
	{
		l_num = map -> x_trg;
		s_num = map -> y_trg;
	}
	else
	{
		l_num = map -> y_trg;
		s_num = map -> x_trg;
	}
	map -> last_db = 0;
	if (s_num - (map -> fair_db) * (map -> mod) > 3)
		map -> fair_db++;
	last_db_mod = l_num - (s_num * (map -> div)) - (s_num / (map -> fair_db));
	if (last_db_mod != 0)
	{
		map -> last_db = s_num / last_db_mod;
		if (s_num / (map -> last_db) - last_db_mod > 3)
			map -> last_db++;
	}
}

static void	if_trg_0(t_map *map)
{
	if (!(map -> x_trg))
	{
		map -> x_trg = 1;
		map -> x_0flag = 1;
	}
	else
		map -> x_0flag = 0;
	if (!(map -> y_trg))
	{
		map -> y_trg = 1;
		map -> y_0flag = 1;
	}
	else
		map -> y_0flag = 0;
}

void	get_src(t_map *map)
{
	if_trg_0(map);
	if (map -> x_trg >= map -> y_trg)
	{
		map -> div = (map -> x_trg) / (map -> y_trg);
		map -> mod = (map -> x_trg) % (map -> y_trg);
		if (!map -> mod)
			map -> fair_db = map -> y_trg;
		else
			map -> fair_db = (map -> y_trg) / (map -> mod);
	}
	else
	{
		map -> div = (map -> y_trg) / (map -> x_trg);
		map -> mod = (map -> y_trg) % (map -> x_trg);
		if (!map -> mod)
			map -> fair_db = map -> x_trg;
		else
			map -> fair_db = (map -> x_trg) / (map -> mod);
	}
	special_case(map);
}

static void	win_ini(t_map *map)
{
	int	x;
	int	y;

	x = map -> x_iter;
	y = map -> y_iter;
	map -> x_win = (map -> cord)[y][x]. x_win;
	map -> y_win = (map -> cord)[y][x]. y_win;
	if (!(map -> y_flag))
	{
		map -> next_x_win = (map -> cord)[y][x + 1]. x_win;
		map -> next_y_win = (map -> cord)[y][x + 1]. y_win;
	}
	else
	{
		map -> next_x_win = (map -> cord)[y + 1][x]. x_win;
		map -> next_y_win = (map -> cord)[y + 1][x]. y_win;
	}
}

void	get_target(t_map *map)
{
	win_ini(map);
	if (map -> next_x_win > map -> x_win)
	{
		map -> back_flag = 0;
		map -> x_trg = map -> next_x_win - map -> x_win;
	}
	else
	{
		map -> back_flag = 1;
		map -> x_trg = map -> x_win - map -> next_x_win;
	}
	map -> y_trg = map -> next_y_win - map -> y_win;
	if (map -> next_y_win < map -> y_win)
		map -> up_flag = 1;
	else
		map -> up_flag = 0;
	if (map -> y_trg < 0)
	{
		map -> y_trg = -(map -> y_trg);
		map -> up_flag = 1;
	}
}
