/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:24:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/02 12:58:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void cl()
{
	system("leaks -q Animal");
}

int main()
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal * wrong = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	wrong->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete wrong;
	atexit(cl);
	return (0);
}
