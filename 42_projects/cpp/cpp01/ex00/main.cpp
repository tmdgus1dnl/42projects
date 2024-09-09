/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:23:45 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/20 18:32:10 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie new_undead_static("s_zombie");
	Zombie *new_undead_dynamic;

	new_undead_dynamic = newZombie("d_zombie");
	if (new_undead_dynamic == 0)
		return (1);
	new_undead_static.announce();
	new_undead_dynamic->announce();
	randomChump("r_zombie");
	delete new_undead_dynamic;
	return (0);
}
