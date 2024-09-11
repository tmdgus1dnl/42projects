/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 17:22:07 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
	std::cout << "ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name)
{
	*this = other;
	std::cout << "ScavTrap copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit_points == 0)
		return ;
	else if (!Energy_points)
	{
		std::cout << name << " out of energy!\n" << std::endl;
		return ;
	}
	Energy_points--;
	std::cout << name << " attacks " << target
		<< ", causing " << Attack_damage << " points of damage!\n"
		<< "Energy points : " << Energy_points  << "\n"
		<< "ps : this is ScavTrap attack :)\n" << std::endl;
}


void ScavTrap::guardGate()
{
	if (this->Hit_points <= 0 || this->Energy_points <= 0)
	{
		std::cout << this->name <<  " cant do that..\n" << std::endl;
		return ;
	}
	std::cout << this->name << " is in Gate keeper mode!!\n" << std::endl;
}
