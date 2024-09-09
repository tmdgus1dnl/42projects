/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:40:29 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:18:58 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombieHorde;

	try
	{
		zombieHorde = new Zombie[N];
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	for (int i = 0; i < N; i++)
		zombieHorde[i] = Zombie(name);
	return (zombieHorde);
}
