/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:56:37 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/03 16:52:32 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : Hit_points(10), Energy_points(10), Attack_damage(0)
{
	this->name = name;
	std::cout << "ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (Hit_points == 0 || Energy_points == 0)
		return ;
	Energy_points--;
	std::cout << name << " attacks " << target
		<< ", causing " << Attack_damage << " points of damage!\n"
		<< "Energy points : " << Energy_points  << "\n"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= Hit_points)
		Hit_points = 0;
	else
		Hit_points -= amount;
	std::cout << name << " attacked, losing " << amount
		<< " points of hit points!\n" << "Hit points : "
		<< Hit_points << "\n" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points == 0 || Energy_points == 0)
		return ;
	Energy_points--;
	Hit_points += amount;
	std::cout << name << " repairing itself, gained " << amount
		<< " points of hit points!\n" << "Energy points : "
		<< Energy_points << " Hit points : " << Hit_points
		<< "\n" << std::endl;
}
