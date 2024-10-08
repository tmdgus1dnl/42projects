/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/03 16:01:17 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char** argv)
{
	pushNums(argv);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::pushNums(const char** argv)
{
	double num;
	char* ptr;

	for (std::size_t i = 1; argv[i]; ++i)
	{
		num = std::strtod(argv[i], &ptr);

		parseInput(num, ptr, argv[i]);

		this->vec.push_back(static_cast<int>(num));
		this->lst.push_back(static_cast<int>(num));
	}
}

void PmergeMe::parseInput(double num, const char* ptr, const char* str) const
{
	if (*ptr || ptr == str)
	   throw std::invalid_argument("Error");

	if (std::floor(num) != num || num > 2147483647 || num < 0)
	   throw std::invalid_argument("Error");
}

void PmergeMe::FJSort()
{

void PmergeMe::printCont(const std::string& Contname)
{
	if (Contname == "vec")
	{
		std::cout << "vector : ";
		for (std::size_t i = 0; i < vec.size(); ++i)
			std::cout << vec[i] << " ";
	}

	if (Contname == "lst")
	{
		std::cout << "list : ";
		for (lst_it it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
	}
	
	std::cout << std::endl;
}
