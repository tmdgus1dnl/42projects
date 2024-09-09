/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:04:00 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:39:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string filter)
{
	this->filter = filter;
	init_table(this->table);
	this->filter_index = this->get_table_index(this->filter);
}

Harl::~Harl()
{
	if (this->filter_index == -1)
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
}

void Harl::init_table(FuncTable *table)
{
	table[0] = &Harl::debug;
	table[1] = &Harl::info;
	table[2] = &Harl::warning;
	table[3] = &Harl::error;
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable!\nI want to speak to the manager now.\n"
		<< std::endl;
}

int Harl::get_table_index(std::string level)
{
	switch (level[0])
	{
		case 'D':
			if (level.compare("DEBUG") == 0)
				return (0);
			break ;
		case 'I':
			if (level.compare("INFO") == 0)
				return (1);
			break ;
		case 'W':
			if (level.compare("WARNING") == 0)
				return (2);
			break ;
		case 'E':
			if (level.compare("ERROR") == 0)
				return (3);
			break ;
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	int index;

	index = this->get_table_index(level);
	this->filter_index = this->get_table_index(this->filter);
	if (this->filter_index == -1)
		return ;
	if (index >= this->filter_index)
		(this->*table[index]) ();
}
