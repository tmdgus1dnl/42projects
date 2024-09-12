/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:24:40 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:10:58 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void cl()
{
	system("leaks -q Brain");
}

int main()
{
	std::cout << "\n------------Constructor-------------\n" << std::endl; 
	Animal** array = new Animal*[6];

	for (int i = 0; i < 6; ++i)
	{
		if (i < 3)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	std::cout << "\n------------sayIdea-------------\n" << std::endl; 

	for (int i = 0; i < 6; ++i)
	{
		std::cout << array[i]->getType() << "\n";
		array[i]->sayIdea();
	}

	std::cout << "\n------------Copy chk-------------\n" << std::endl; 
	Cat first_Cat;
	Cat copy_Cat(first_Cat);
	first_Cat.sayIdea();
	copy_Cat.sayIdea();
	first_Cat = copy_Cat;
	first_Cat.sayIdea();
	copy_Cat.sayIdea();

	std::cout << "\n------------Destroyer-------------\n" << std::endl; 
	for (int i = 0; i < 6; ++i)
		delete array[i];

	delete[] array;
	atexit(cl);
	return (0);
}
