/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:01:19 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/10 19:23:30 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void cl()
{
	system("leaks -q Materia");
}

int main()
{
	std::cout << "\n-------------Constructor-------------\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* Cloud = new Character("Cloud");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("cure");
	Cloud->equip(tmp);
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("cure");
	Cloud->equip(tmp);
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);

	ICharacter* Zack = new Character("Zack");

	std::cout << "\n-------------use Materia-------------\n" << std::endl;
	Cloud->use(0, *Zack);
	Cloud->use(1, *Zack);
	Cloud->use(2, *Zack);
	Cloud->use(3, *Zack);
	Cloud->use(4, *Zack);

	std::cout << "\n-------------unequip-------------\n" << std::endl;
	Cloud->unequip(0);
	Cloud->unequip(1);
	Cloud->use(0, *Zack);
	Cloud->use(1, *Zack);
	Cloud->equip(Floor::getInstance().pickupMateria());
	Cloud->equip(Floor::getInstance().pickupMateria());
	Cloud->use(0, *Zack);
	Cloud->use(1, *Zack);

	std::cout << "\n-------------Copy-------------\n" << std::endl;
	Character* C_Zack = dynamic_cast<Character*>(Zack);
	Character* C_Cloud = dynamic_cast<Character*>(Cloud);
	*C_Zack = *C_Cloud;
	std::cout << Zack->getName() << std::endl;
	Zack->use(0, *Cloud);
	Zack->use(1, *Cloud);

	std::cout << "\n-------------Destroyer-------------\n" << std::endl;
	delete Zack;
	delete Cloud;
	delete src;
	atexit(cl);
	return (0);
}
