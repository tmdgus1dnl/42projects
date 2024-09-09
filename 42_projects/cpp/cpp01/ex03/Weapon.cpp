/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:00:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/21 12:03:40 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
