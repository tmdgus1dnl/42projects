/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 16:44:22 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_Hit_points();
	set_Energy_points();
	set_Attack_damage();
	std::cout << "FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name)
{
	*this = other;
	std::cout << "FragTrap copy constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->Hit_points == 0 || this->Energy_points == 0)
		return ;
	std::cout << this->get_name() << " requests highFives!\n" << std::endl;
}

void FragTrap::set_Hit_points()
{
	Hit_points = 100;
}

void FragTrap::set_Energy_points()
{
	Energy_points = 100;
}

void FragTrap::set_Attack_damage()
{
	Attack_damage = 30;
}
