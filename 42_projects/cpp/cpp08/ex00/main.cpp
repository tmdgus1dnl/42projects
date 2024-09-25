/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:34:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 12:28:11 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> lst;
	std::vector<int> vec;

	for (int i = 0; i < 9; ++i)
	{
		lst.push_back(i + 1);
		vec.push_back(i + 1);
	}

	try
	{
		std::list<int>::iterator it_lst = easyfind(lst, 4);
		std::cout << "list : " << *it_lst << std::endl;
	}

	catch (std::runtime_error& e)
	{
		std::cout << e.what() << " in list" << std::endl;
	}

	try
	{
		std::vector<int>::iterator it_vec = easyfind(vec, 10);
		std::cout << "vector : " << *it_vec << std::endl;
	}

	catch (std::runtime_error& e)
	{
		std::cout << e.what() << " in vector" << std::endl;
	}
	return (0);
}
