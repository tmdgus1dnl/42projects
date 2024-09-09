/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:48:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/19 11:28:47 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "h_bundle.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class PhoneBook
{
	private :
		Contact contacts[8];
		int	size;
		int	cnt;

	public :
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();
		void add();
		void search();
		void get_index_buffer(int index_buffer[8]);
};

#endif
