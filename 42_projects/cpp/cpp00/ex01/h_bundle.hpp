/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_bundle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:55:18 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/18 17:50:28 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BUNDLE_HPP
#define H_BUNDLE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool name_valid_chk(std::string input);
bool number_valid_chk(std::string input);
bool general_valid_chk(std::string input);
bool index_valid_chk(std::string input, int index_buffer[8]);
bool is_empty(int index_buffer[8]);
void trim_input(std::string& input);
void get_first_name(std::string& input);
void get_last_name(std::string& input);
void get_nick_name(std::string& input);
void get_phone_number(std::string& input);
void get_secret(std::string& input);
void retry_input_name(std::string &input, std::string prompt);
void retry_input_num(std::string &input);
void retry_input_others(std::string &input, std::string prompt);
void print_border();
void print_seperator();
void print_contact_name(std::string name);
void print_contact_index(int index);
void print_helper();
std::string erase_all_space(std::string input);

#endif
