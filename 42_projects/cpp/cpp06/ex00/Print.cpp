/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:00:11 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 13:25:53 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"

void printChar(double& result)
{
	std::cout << "char : ";

	if (std::isinf(result) || std::isnan(result))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(result)) ||
			result > CHAR_MAX || CHAR_MIN > result)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(result) << "'" << std::endl;
}

void printInt(double& result)
{
	std::cout << "int : ";

	if (std::isinf(result) || std::isnan(result) || 
			result > INT_MAX || INT_MIN > result)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(result) << std::endl;
}

void printFloat(double& result)
{
	std::cout << "float : ";

	if (std::isinf(static_cast<float>(result)) || std::isnan(result))
	{
		std::cout << std::showpos << static_cast<float>(result) << "f" << std::endl;
		return ;
	}
	if (fmod(result, 1.0) == 0.0)
		std::cout << static_cast<float>(result) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(result) << "f" << std::endl;
}

void printDouble(double& result)
{
	std::cout << "double : ";

	if (std::isinf(result) || std::isnan(result))
	{
		std::cout << std::showpos << result << std::endl;
		return ;
	}
	if (fmod(result, 1.0) == 0.0)
		std::cout << result << ".0" << std::endl;
	else
		std::cout << result << std::endl;
}
