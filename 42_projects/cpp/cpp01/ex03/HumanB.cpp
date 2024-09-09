/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:42:42 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:23:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	weapon_type = 0;
	this->name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(const Weapon& weapon_type)
{
	this->weapon_type = &weapon_type;
}

void HumanB::attack()
{
	if (!this->weapon_type)
		std::cout << name << " does not have a weapon!" << std::endl;
	else
		std::cout << this->name << " attacks with their "
			<< this->weapon_type->getType() << std::endl;
}
