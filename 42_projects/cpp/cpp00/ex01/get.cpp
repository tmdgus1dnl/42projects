/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:55:03 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 17:41:49 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

void get_first_name(std::string& input)
{
	std::string prompt;

	prompt = "First name : ";
	std::cout << prompt;
	std::getline(std::cin, input);
	trim_input(input);
	if (name_valid_chk(input) == true)
		return ;
	else
		retry_input_name(input, prompt);
}

void get_last_name(std::string& input)
{
	std::string prompt;

	prompt = "last name : ";
	std::cout << prompt;
	std::getline(std::cin, input);
	trim_input(input);
	if (name_valid_chk(input) == true)
		return ;
	else
		retry_input_name(input, prompt);
}

void get_nick_name(std::string& input)
{
	std::string prompt;

	prompt = "Nickname : ";
	std::cout << prompt;
	std::getline(std::cin, input);
	trim_input(input);
	if (general_valid_chk(input) == true)
		return ;
	else
		retry_input_others(input, prompt);
}

void get_phone_number(std::string& input)
{
	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	trim_input(input);
	input = erase_all_space(input);
	if (number_valid_chk(input) == true)
		return ;
	else
		retry_input_num(input);
}

void get_secret(std::string& input)
{
	std::string prompt;

	prompt = "Darkest secret.. : ";
	std::cout << prompt;
	std::getline(std::cin, input);
	trim_input(input);
	if (general_valid_chk(input) == true)
		return ;
	else
		retry_input_others(input, prompt);
}
