/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:19:58 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:09:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	mind = new Brain();
	mind->mindset("I want bones");
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	mind = 0;
	*this = other;
	std::cout << "Dog copy created" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		if (mind)
			delete mind;
		mind = new Brain();
		mind->mindset(other.getBrain());
	}
	return (*this);
}

Dog::~Dog()
{
	delete mind;
	std::cout << "Dog is gone" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void Dog::sayIdea() const
{
	std::cout << mind->getIdea() << std::endl;
}

const Brain& Dog::getBrain() const
{
	return(*(this-> mind));
}
