/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:25:47 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 11:45:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

void trim_input(std::string& input)
{
	size_t start;
	size_t end;

	start = input.find_first_not_of(" \t");
	input.erase(0, start);
	end = input.find_last_not_of(" \t");
	input.erase(end + 1);
}

std::string erase_all_space(std::string input)
{
	std::string result;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ' && input[i] != '\t')
			result += input[i];
	}
	return (result);
}
