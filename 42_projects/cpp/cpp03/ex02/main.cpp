/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:56 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/01 11:31:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap first_trap("FragTrap");
	FragTrap copy_trap(first_trap);

	first_trap.attack("Rachet");
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.beRepaired(5);
	first_trap.highFivesGuys();
	copy_trap.attack("Clank");
	copy_trap.takeDamage(5);
	copy_trap.beRepaired(5);
	copy_trap.highFivesGuys();
	copy_trap.takeDamage(100);
	copy_trap.highFivesGuys();
	return (0);
}
