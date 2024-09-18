/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:33:48 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 13:26:17 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Src.hpp"

void cl()
{
	system("leaks -q Identify");
}

int main(void)
{
	//Pointer
	
	Base* ptr1;
	Base* ptr2;
	Base* ptr3;

	ptr1 = generate();
	sleep(1);
	ptr2 = generate();
	sleep(1);
	ptr3 = generate();

	std::cout << "\n-------------Pointer-------------\n" << std::endl;
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);

	//Reference
	
	std::cout << "\n-------------Reference-------------\n" << std::endl;
	if (ptr1)
	{
		Base& ref1 = *ptr1;
		identify(ref1);
	}
	if (ptr2)
	{
		Base& ref2 = *ptr2;
		identify(ref2);
	}
	if (ptr3)
	{
		Base& ref3 = *ptr3;
		identify(ref3);
	}

	atexit(cl);
	if (ptr1)
		delete ptr1;
	if (ptr2)
		delete ptr2;
	if (ptr3)
		delete ptr3;
	
	return (0);
}
