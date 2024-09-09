/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:48:51 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 17:54:18 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "h_bundle.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class Contact
{
	private :
		int index;
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public :
		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();
		int get_index();
		void add_contact_info(int cnt);
		void print_contact_id();
		void print_contact_info();
};

#endif
