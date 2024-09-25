/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:45:25 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 15:54:33 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(10);
	std::list<int> lst;

	for (int i = 0; i < 5; ++i)
		lst.push_back(i);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addAllNumbers(lst);
	}

	catch (std::exception& e)
	{
		std::cout << "Vector is Full!" << std::endl;
	}

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	catch (std::exception& e)
	{
		std::cout << "Vector has insufficient elements." << std::endl;
	}

	return (0);
}
