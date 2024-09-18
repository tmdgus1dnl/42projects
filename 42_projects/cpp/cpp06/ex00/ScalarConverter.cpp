/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:07:39 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 11:03:59 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double ScalarConverter::convert(const std::string& string)
{
	double result;
	char*  end = NULL;
	const char*  str = string.c_str();

	result = std::strtod(str, &end);
	if (end && end == str && string.length() == 1)
	{
		char ch = string[0];
		return (static_cast<double>(ch));
	}
	else if (end && end == str)
		throw std::bad_alloc();

	return (result);
}
