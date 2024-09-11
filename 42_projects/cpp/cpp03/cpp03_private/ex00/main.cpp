/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:56 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/29 11:36:17 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap first_trap("ClapTrap");
	ClapTrap copy_trap(first_trap);

	first_trap.attack("Rachet");
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.takeDamage(5);
	first_trap.beRepaired(5);
	copy_trap.attack("Clank");
	copy_trap.takeDamage(5);
	copy_trap.beRepaired(5);
	return (0);
}
