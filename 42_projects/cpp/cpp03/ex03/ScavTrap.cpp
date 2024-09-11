/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 16:44:02 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	set_Hit_points();
	set_Energy_points();
	set_Attack_damage();
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
		name = other.name;
		Hit_points = other.Hit_points;
		Energy_points = other.Energy_points;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->Hit_points == 0 || this->Energy_points == 0)
		return ;
	std::cout << this->get_name() << " is in Gate keeper mode!!\n" << std::endl;
}

void ScavTrap::set_Hit_points()
{
	Hit_points = 100;
}

void ScavTrap::set_Energy_points()
{
	Energy_points = 50;
}

void ScavTrap::set_Attack_damage()
{
	Attack_damage = 20;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit_points == 0 || Energy_points == 0)
		return ;
	Energy_points--;
	std::cout << get_name() << " attacks " << target
		<< ", causing " << Attack_damage << " points of damage!\n"
		<< "Energy points : " << Energy_points << "\n"
		<< "ps : This is ScavTrap attack :)\n" << std::endl;
}
