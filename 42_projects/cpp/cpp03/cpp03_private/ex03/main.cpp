/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:56 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 15:29:14 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap first_trap("DiamondTrap");
	DiamondTrap copy_trap(first_trap);
	ClapTrap clappy("ClapTrap");

	first_trap.attack("Rachet");
	first_trap.whoAmI();
	copy_trap.attack("Clank");
	copy_trap.whoAmI();
	first_trap.takeDamage(5);
	first_trap.beRepaired(5);
	first_trap.highFivesGuys();
	first_trap.guardGate();
	clappy.takeDamage(5);
	clappy.beRepaired(5);
	return (0);
}
