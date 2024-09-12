/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:39:08 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:46:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		vault[i] = 0;
	std::cout << "MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
	std::cout << "MateriaSource copy created" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			AMateria* tmp;
			tmp = other.getVault(i);
			if (vault[i])
				delete vault[i];
			vault[i] = tmp;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (vault[i])
			delete vault[i];
	}
	std::cout << "MateriaSource deleted" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!vault[i])
		{
			vault[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (vault[i] && vault[i]->getType() == type)
			return (vault[i]->clone());
	}
	return (0);
}

AMateria* MateriaSource::getVault(int idx) const
{
	if (idx >= 0 && idx < 4 && vault[idx])
		return (vault[idx]->clone());
	else
		return (0);
}
