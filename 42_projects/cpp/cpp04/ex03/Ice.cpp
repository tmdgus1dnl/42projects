/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:57:02 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:28 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructed" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.getType())
{
	*this = other;
	std::cout << "Ice copy constructed" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	other.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destroyed" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}
