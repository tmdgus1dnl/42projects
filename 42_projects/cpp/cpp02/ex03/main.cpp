/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:45:04 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/27 18:54:56 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(2.5, 4.33);
	Point point(2.5, 2);

	if (bsp(a, b, c, point) == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is out of triangle" << std::endl;
	return (0);
}
