/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:00:30 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/20 11:51:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private :
		std::string type;

	public :
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		void  setType(std::string new_type);
};

#endif
