/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructed" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.getType())
{
	*this = other;
	std::cout << "Cure copy constructed" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	other.getType();
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName()
		<< "'s wounds *" << std::endl;
}
