/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:27:46 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/20 12:46:25 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_bundle.hpp"

Contact::Contact() : index(-1) {}

Contact::Contact(const Contact& other) : index(other.index) {}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
		this->index = other.index;
	return (*this);
}

Contact::~Contact() {}

void Contact::add_contact_info(int cnt)
{
	std::string input;

	get_first_name(input);
	firstname = input;
	get_last_name(input);
	lastname = input;
	get_nick_name(input);
	nickname = input;
	get_phone_number(input);
	phone_number = input;
	get_secret(input);
	darkest_secret = input;
	index = cnt;
}

int	Contact::get_index()
{
	return (index);
}

void Contact::print_contact_id()
{
	print_contact_index(index);
	print_contact_name(firstname);
	print_contact_name(lastname);
	print_contact_name(nickname);
	std::cout << "|";
}

void Contact::print_contact_info()
{
	std::cout << "\nFirst name : " << firstname << "\n";
	std::cout << "Last name : " << lastname << "\n";
	std::cout << "Nickname : " << nickname << "\n";
	std::cout << "Phone number : " << phone_number << "\n";
	std::cout << "Darkest secret.. : " << darkest_secret << "\n\n";
}
