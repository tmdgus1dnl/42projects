/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:33:22 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/10 19:23:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {}

Character::Character(std::string const & name)
{
	this->name = name;
	for (int i = 0; i < 4; ++i)
		slot[i] = 0;
	std::cout << "Character created" << std::endl;
}

Character::Character(const Character& other)
{
	*this = other;
	std::cout << "Character copy created" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.getName();
		for (int i = 0; i < 4; ++i)
		{
			AMateria* tmp;
			tmp = other.getSlot(i);
			if (slot[i])
				delete slot[i];
			slot[i] = tmp;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i])
			delete slot[i];
	}
	std::cout << "Character deleted" << std::endl;
}

std::string const & Character::getName() const
{
	return (name);
}

AMateria* Character::getSlot(int idx) const
{
	if (idx >= 0 && idx < 4 && slot[idx])
		return (slot[idx]->clone());
	else
		return (0);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!slot[i])
		{
			slot[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && slot[idx])
	{
		Floor::getInstance().dropMateria(slot[idx]);
		slot[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
}
