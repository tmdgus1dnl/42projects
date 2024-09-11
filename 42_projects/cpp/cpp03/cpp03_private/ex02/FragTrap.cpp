/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:09 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 17:12:49 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_FragTrap_Hit_points(100);
	set_FragTrap_Energy_points(100);
	set_FragTrap_Attack_damage(30);
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
		set_FragTrap_Hit_points(other.get_Hit_points());
		set_FragTrap_Energy_points(other.get_Energy_points());
		set_FragTrap_Attack_damage(other.get_Attack_damage());
		set_FragTrap_name(other.get_name());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->Hit_points() <= 0 || this->Energy_points() <= 0)
	{
		std::cout << this->name() << " cant do that..\n" << std::endl;
		return ;
	}
	std::cout << this->name() << " requests highFives!\n" << std::endl;
}
