/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:56 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/29 11:38:57 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap first_trap("ScavTrap");
	ScavTrap copy_trap(first_trap);

	first_trap.attack("Rachet");
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.beRepaired(5);
	first_trap.guardGate();
	copy_trap.attack("Clank");
	copy_trap.takeDamage(5);
	copy_trap.beRepaired(5);
	copy_trap.guardGate();
	copy_trap.takeDamage(100);
	copy_trap.guardGate();
	return (0);
}
