/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:23:45 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/22 11:18:58 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* new_zombieHorde;
	int		N;

	N = 10;
	new_zombieHorde = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		new_zombieHorde[i].announce();
	delete[] new_zombieHorde;
	return (0);
}
