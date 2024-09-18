/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:06:00 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/15 19:17:00 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Print.hpp"

int main(int argc, char **argv)
{
	double result;

	if (argc != 2)
		return (1);

	try
	{
		result = ScalarConverter::convert(argv[1]);
	}

	catch (std::bad_alloc& e)
	{
		std::cout << "Invalid input, Conversion failed" << std::endl;
		return (1);
	}
	
	printChar(result);
	printInt(result);
	printFloat(result);
	printDouble(result);

	return (0);
}
