/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 15:29:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_Hit_points();
	set_Energy_points();
	set_Attack_damage();
	std::cout << "FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.get_name())
{
	*this = other;
	std::cout << "FragTrap copy constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->get_Hit_points() <= 0 || this->get_Energy_points() <= 0)
	{
		std::cout << this->get_name() << " cant do that..\n" << std::endl;
		return ;
	}
	std::cout << this->get_name() << " requests highFives!\n" << std::endl;
}

void FragTrap::set_Hit_points()
{
	ClapTrap::set_Hit_points(100);
}

void FragTrap::set_Energy_points()
{
	ClapTrap::set_Energy_points(100);
}

void FragTrap::set_Attack_damage()
{
	ClapTrap::set_Attack_damage(30);
}

void FragTrap::attack(const std::string& target)
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
		<< "This is FragTrap attack\n" << std::endl;
}
