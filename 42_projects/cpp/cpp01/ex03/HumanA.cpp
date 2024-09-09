/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:20:26 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/19 16:35:48 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_type(weapon)
{
	this->name = name;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << (this->weapon_type).getType()
		<< std::endl;
}
