/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:56:37 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 15:19:31 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= Hit_points)
		Hit_points = 0;
	else
		Hit_points -= amount;
	std::cout << get_name() << " attacked, losing " << amount
		<< " points of hit points!\n" << "Hit points : "
		<< Hit_points << "\n" << std::endl;
	if (Hit_points == 0)
		std::cout << get_name() << " is ded..\n" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points == 0)
		return ;
	else if (!Energy_points)
	{
		std::cout << get_name() << " out of energy!\n" << std::endl;
		return ;
	}
	Energy_points--;
	Hit_points += amount;
	std::cout << get_name() << " repairing itself, gained " << amount
		<< " points of hit points!\n" << "Energy points : "
		<< Energy_points << " Hit points : " << Hit_points
		<< "\n" << std::endl;
}

unsigned int ClapTrap::get_Hit_points() const
{
	return (this->Hit_points);
}

unsigned int ClapTrap::get_Energy_points() const
{
	return (this->Energy_points);
}

unsigned int ClapTrap::get_Attack_damage() const
{
	return (this->Attack_damage);
}

std::string ClapTrap::get_name() const
{
	return (this->name);
}

void ClapTrap::set_Hit_points(unsigned int amount)
{
	this->Hit_points = amount;
}

void ClapTrap::set_Energy_points(unsigned int amount)
{
	this->Energy_points = amount;
}

void ClapTrap::set_Attack_damage(unsigned int amount)
{
	this->Attack_damage = amount;
}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}

void ClapTrap::set_Hit_points()
{
	set_Hit_points(10);
}

void ClapTrap::set_Energy_points()
{
	set_Energy_points(10);
}

void ClapTrap::set_Attack_damage()
{
	set_Attack_damage(0);
}
