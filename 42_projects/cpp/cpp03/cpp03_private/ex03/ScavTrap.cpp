/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 14:44:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	set_Hit_points();
	set_Energy_points();
	set_Attack_damage();
	std::cout << "ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.get_name())
{
	*this = other;
	std::cout << "ScavTrap copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::set_Hit_points(other.get_Hit_points());
		ClapTrap::set_Energy_points(other.get_Energy_points());
		ClapTrap::set_Attack_damage(other.get_Attack_damage());
		ClapTrap::set_name(other.get_name());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->get_Hit_points() <= 0 || this->get_Energy_points() <= 0)
	{
		std::cout << this->get_name() <<  " cant do that..\n" << std::endl;
		return ;
	}
	std::cout << this->get_name() << " is in Gate keeper mode!!\n" << std::endl;
}

void ScavTrap::set_Hit_points()
{
	ClapTrap::set_Hit_points(100);
}

void ScavTrap::set_Energy_points()
{
	ClapTrap::set_Energy_points(50);
}

void ScavTrap::set_Attack_damage()
{
	ClapTrap::set_Attack_damage(20);
}

void ScavTrap::attack(const std::string& target)
{
	if (get_Hit_points() == 0)
		return ;
	else if (!get_Energy_points())
	{
		std::cout << get_name() << " out of energy!\n" << std::endl;
		return ;
	}
	ClapTrap::set_Energy_points(get_Energy_points() - 1);
	std::cout << get_name() << " attacks " << target
		<< ", causing " << get_Attack_damage() << " points of damage!\n"
		<< "Energy points : " << get_Energy_points()  << "\n"
		<< "This is ScavTrap attack\n" << std::endl;
}
