/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:34:30 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:45:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() {}

Floor::Floor(const Floor& other)
{
	other.empty_func();
}

Floor& Floor::operator=(const Floor& other)
{
	other.empty_func();
	return (*this);
}

Floor::~Floor()
{
	for (int i = 0; i < 4; ++i)
	{
		if (floor[i])
			delete floor[i];
	}
}	

Floor& Floor::getInstance()
{
	static Floor instance;
	return (instance);
}

AMateria* Floor::pickupMateria()
{
	for (int i = 0; i < 4; ++i)
	{
		if (floor[i])
		{
			AMateria *tmp;
			tmp = floor[i];
			floor[i] = 0;
			std::cout << "Picked up Materia \"" << tmp->getType()
				<< "\"!" << std::endl;
			return (tmp);
		}
	}
	return (0);
}

void Floor::dropMateria(AMateria* m)
{
	static int insert;

	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!floor[i])
		{
			floor[i] = m;
			std::cout << "Dropped Materia \"" << m->getType()
				<< "\"" << std::endl;
			return ;
		}
	}
	delete floor[insert];
	floor[insert] = m;
	insert++;
	if (insert == 4)
		insert = 0;
}

void Floor::empty_func() const {}
