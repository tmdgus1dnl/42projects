/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:41:44 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/13 18:55:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe containers(argv);
		containers.FJSort();
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
