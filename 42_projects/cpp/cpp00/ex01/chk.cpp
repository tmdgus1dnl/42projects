/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:24:50 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/20 14:19:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

bool general_valid_chk(std::string input)
{
	if (!std::cin)
		std::exit(1);
	else if (input.size() == 0)
		return (false);
	else
		return (true);
}

bool name_valid_chk(std::string input)
{
	if (general_valid_chk(input) == false)
		return (false);
	for (int i = 0; i < input.size(); i++)
	{
		if (!std::isalpha(input[i]) && !std::isspace(input[i]))
			return (false);
	}
	return (true);
}

bool number_valid_chk(std::string input)
{
	if (general_valid_chk(input) == false)
		return (false);
	for (int i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]) && !std::isspace(input[i]))
			return (false);
	}
	return (true);
}

bool is_empty(int index_buffer[8])
{
	for (int i = 0; i < 8; i++)
	{
		if (index_buffer[i] != -1)
			return (false);
	}
	return (true);
}

bool index_valid_chk(std::string input, int index_buffer[8])
{
	int	input_index;

	try
	{
		input_index = std::stoi(input);
		if (input_index < 0 || 7 < input_index)
			throw (std::out_of_range("\nInput index out of range [0, 7]\n"));
		for (int i = 0; i < 8; i++)
		{
			if (input_index == index_buffer[i])
				return (true);
		}
		throw (std::runtime_error("\nIndex not found\n"));
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\nEnter only numeric characters\n\n";
		return (false);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << "\n";
		return (false);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << "\n";
		return (false);
	}
}
