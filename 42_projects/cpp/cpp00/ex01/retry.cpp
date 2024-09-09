/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:48:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 17:41:48 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

void retry_input_name(std::string &input, std::string prompt)
{
	while (1)
	{
		std::cout << "\nEnter only alphabetic characters\n\n";
		std::cout << prompt;
		std::getline(std::cin, input);
		trim_input(input);
		if (name_valid_chk(input) == true)
			break ;
	}
}

void retry_input_num(std::string &input)
{
	while (1)
	{
		std::cout << "\nEnter only numeric characters\n\n";
		std::cout << "Phone number : ";
		std::getline(std::cin, input);
		trim_input(input);
		input = erase_all_space(input);
		if (number_valid_chk(input) == true)
			break ;
	}
}

void retry_input_others(std::string &input, std::string prompt)
{
	while (1)
	{
		std::cout << "\nEmpty input is not allowed\n\n";
		std::cout << prompt;
		std::getline(std::cin, input);
		trim_input(input);
		if (general_valid_chk(input) == true)
			break ;
	}
}
