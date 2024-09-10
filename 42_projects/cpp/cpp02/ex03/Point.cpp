/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:36:28 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/27 17:10:04 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}

Point::Point(const float x_float, const float y_float) : x(x_float), y(y_float) {}

Point::Point(const Point& other)
{
	*this = other;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		(const_cast<Fixed&>(this->x)).setRawBits(other.x.getRawBits());
		(const_cast<Fixed&>(this->y)).setRawBits(other.y.getRawBits());
	}
	return (*this);
}

float Point::get_float_x() const
{
	return (x.toFloat());
}

float Point::get_float_y() const
{
	return (y.toFloat());
}

Point::~Point() {}
