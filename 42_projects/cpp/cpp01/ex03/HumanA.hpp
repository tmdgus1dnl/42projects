/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:20:24 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/19 16:35:37 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private :
		Weapon& weapon_type;
		std::string name;
	
	public :
		HumanA(std::string name, Weapon& weapon_type);
		~HumanA();
		void attack();
};

#endif
