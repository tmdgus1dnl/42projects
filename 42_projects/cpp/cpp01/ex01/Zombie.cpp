/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:04:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:18:41 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default constructor called" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other)
		this->name = other.name;
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << "RIP " << name << ".." << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
