/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:43:43 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 18:31:16 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

PhoneBook::PhoneBook() : size(8), cnt(0) {}

PhoneBook::PhoneBook(const PhoneBook& other) : size(8), cnt(other.cnt) {}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this != &other)
		this->cnt = other.cnt;
	return (*this);
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
	std::string	input;

	contacts[cnt].add_contact_info(cnt);
	cnt++;
	if (cnt == size)
		cnt = 0;
}

void PhoneBook::get_index_buffer(int index_buffer[8])
{
	int index;

	for (int i = 0; i < 8; i++)
	{
		index = contacts[i].get_index();
		index_buffer[i] = index;
	}
}

void PhoneBook::search()
{
	int	input_index;
	int	index_buffer[8];
	std::string input;

	get_index_buffer(index_buffer);
	if (is_empty(index_buffer) == true)
	{
		std::cout << "\nNo contacts in PhoneBook, ADD first.\n\n";
		return ;
	}
	print_border();
	print_helper();
	for (int i = 0; index_buffer[i] != -1 && i < 8; i++)
	{
		print_seperator();
		contacts[i].print_contact_id();
		std::cout << std::endl;
	}
	print_border();
	while (1)
	{
		std::cout << "input contact index you want to view\n";
		std::cout << "  : ";
		std::getline(std::cin, input);
		if (general_valid_chk(input) == false)
			continue ;
		else if (index_valid_chk(input, index_buffer) == false)
			continue;
		input_index = std::stoi(input);
		contacts[input_index].print_contact_info();
		break ;
	}
}
