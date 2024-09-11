/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:06:46 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/03 17:03:53 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name")
{
	DiamondTrap::name = name;
	FragTrap::set_Hit_points();
	ScavTrap::set_Energy_points();
	FragTrap::set_Attack_damage();
	std::cout << "DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other.ClapTrap::name),
	ScavTrap(other.ClapTrap::name),
	FragTrap(other.ClapTrap::name)
{
	*this = other;
	std::cout << "DiamondTrap copy constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		Hit_points = other.Hit_points;
		Energy_points = other.Energy_points;
		Attack_damage = other.Attack_damage;
		this->name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::whoAmI() const
{
	if (Hit_points == 0 || Energy_points == 0)
		return ;
	std::cout << "DiamondTrap name : " << DiamondTrap::name << "\n";
	std::cout << "ClapTrap name : " << ClapTrap::name << "\n"
		<< std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::get_name() const
{
	return (this->name);
}
