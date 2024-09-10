/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:17:58 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/28 11:37:40 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static float get_cross(Point const start, Point const end, Point const point)
{
	float start_to_end_x;
	float start_to_end_y;
	float start_to_point_x;
	float start_to_point_y;
	float cross;

	start_to_end_x = end.get_float_x() - start.get_float_x();
	start_to_end_y = end.get_float_y() - start.get_float_y();
	Point start_to_end(start_to_end_x, start_to_end_y);

	start_to_point_x = point.get_float_x() - start.get_float_x();
	start_to_point_y = point.get_float_y() - start.get_float_y();
	Point start_to_point(start_to_point_x, start_to_point_y);

	cross = (start_to_end.get_float_x() * start_to_point.get_float_y()) -
		(start_to_end.get_float_y() * start_to_point.get_float_x());
	return (cross);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float cross1;
	float cross2;
	float cross3;

	cross1 = get_cross(a, b, point);
	cross2 = get_cross(b, c, point);
	cross3 = get_cross(c, a, point);

	if (cross1 > 0 && cross2 > 0 && cross3 > 0)
		return (true);
	if (cross1 < 0 && cross2 < 0 && cross3 < 0)
		return (true);
	return (false);
}
