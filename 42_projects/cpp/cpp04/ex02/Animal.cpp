/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:10:39 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 14:58:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy created" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal is gone" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "choose Animal type for making sound.." << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::sayIdea() const
{
	std::cout << "choose Animal type to get an idea..\n" << std::endl;
}
