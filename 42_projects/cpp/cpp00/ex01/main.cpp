/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:34:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 11:21:18 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string input;

	std::cout << "My Awesome PhoneBook\n\n";
	while (1)
	{
		std::cout << "input command (ex)ADD, SEARCH, EXIT)" << "\n";
		std::cout << "	: ";
		std::getline(std::cin, input);
		if (general_valid_chk(input) == false)
			continue ;
		trim_input(input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
