/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Src.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:37:23 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 12:41:05 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Src.hpp"

Base* generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "A created" << std::endl;
			return new A();
		case 1:
			std::cout << "B created" << std::endl;
			return new B();
		case 2:
			std::cout << "C created" << std::endl;
			return new C();
	}
	return (0);
}

void identify(Base* p)
{
	if (!p)
		return ;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Type not found\n" << std::endl;
}

bool downcastA(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return (true);
	}

	catch (std::exception& e)
	{
		return (false);
	}
}

bool downcastB(Base& p)
{
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return (true);
	}

	catch (std::exception& e)
	{
		return (false);
	}
}

bool downcastC(Base& p)
{
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return (true);
	}

	catch (std::exception& e)
	{
		return (false);
	}
}

void identify(Base& p)
{
	try
	{
		bool flag = false;
		flag = downcastA(p);
		if (flag == false)
			flag = downcastB(p);
		if (flag == false)
			flag = downcastC(p);
		if (flag == false)
			throw std::runtime_error("Type not found\n");
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
