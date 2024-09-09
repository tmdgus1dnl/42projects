/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:59:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/19 11:18:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
	private :
		std::string name;

	public :
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
