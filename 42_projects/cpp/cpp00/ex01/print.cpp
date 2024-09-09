/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:53:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 11:28:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

void print_border()
{
	std::cout << "@===========================================@\n";
}

void print_seperator()
{
	std::cout << "|-------------------------------------------|\n";
}

void print_helper()
{
	std::cout << "|  index   |  first   |   last   |   nick   |\n";
}

void print_contact_name(std::string name)
{
	if (name.length() > 10)
	{
		name[9] = '.';
		name.erase(10);
	}
	std::cout << "|";
	std::cout << std::setw(10) << std::right << name;
}

void print_contact_index(int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << std::right << index;
}
