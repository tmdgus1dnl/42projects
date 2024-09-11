/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:06:46 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 15:21:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name")
{
	DiamondTrap::name = name;
	set_Hit_points();
	set_Energy_points();
	set_Attack_damage();
	std::cout << "DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other.ClapTrap::get_name()),
	ScavTrap(other.ClapTrap::get_name()),
	FragTrap(other.ClapTrap::get_name())
{
	*this = other;
	std::cout << "DiamondTrap copy constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::set_Hit_points(other.get_Hit_points());
		ClapTrap::set_Energy_points(other.get_Energy_points());
		ClapTrap::set_Attack_damage(other.get_Attack_damage());
		this->name = ((other.DiamondTrap::get_name()));
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name : " << DiamondTrap::name << "\n";
	std::cout << "ClapTrap name : " << ClapTrap::get_name() << "\n"
		<< std::endl;
}

void DiamondTrap::set_Hit_points()
{
	FragTrap::set_Hit_points();
}

void DiamondTrap::set_Energy_points()
{
	ScavTrap::set_Energy_points();
}

void DiamondTrap::set_Attack_damage()
{
	FragTrap::set_Attack_damage();
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::get_name() const
{
	return (this->name);
}
