/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:28:34 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/19 11:32:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* new_undead;

	try
	{
		new_undead = new Zombie(name);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (new_undead);
}
