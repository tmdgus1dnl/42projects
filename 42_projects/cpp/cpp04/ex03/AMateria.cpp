/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:06:45 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:42 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "Materia created" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	std::cout << "Materia copy created" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	other.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Materia deleted" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia type unknown, cant use it to "
		<< target.getName() << std::endl;
}
