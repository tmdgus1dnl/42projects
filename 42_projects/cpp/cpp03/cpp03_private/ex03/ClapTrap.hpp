/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:53:23 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 15:47:35 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	private :
		std::string name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		unsigned int Attack_damage;
	
	public :
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int get_Hit_points() const;
		unsigned int get_Energy_points() const;
		unsigned int get_Attack_damage() const;
		virtual std::string get_name() const;
		void set_Hit_points(unsigned int amount);
		void set_Energy_points(unsigned int amount);
		void set_Attack_damage(unsigned int amount);
		void set_name(std::string name);
		virtual void set_Hit_points();
		virtual void set_Energy_points();
		virtual void set_Attack_damage();
};
