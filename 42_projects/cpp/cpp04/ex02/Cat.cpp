/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:22:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:09:16 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	mind = new Brain();
	mind->mindset("I want fish");
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	mind = 0;
	*this = other;
	std::cout << "Cat copy created" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
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

Cat::~Cat()
{
	delete mind;
	std::cout << "Cat is gone" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meeow" << std::endl;
}

void Cat::sayIdea() const
{
	std::cout << mind->getIdea() << std::endl;
}

const Brain& Cat::getBrain() const
{
	return(*(this->mind));
}
