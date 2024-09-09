/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:41:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:23:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	private :
		const Weapon* weapon_type;
		std::string name;
	
	public :
		HumanB(std::string name);
		~HumanB();
		void setWeapon(const Weapon& weapon_type);
		void attack();
};

#endif
