/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/10 19:20:28 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char** argv)
{
	pushNums(argv);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(double num, const char* ptr, const char* str) const
{
	if (*ptr || ptr == str)
	   throw std::invalid_argument("Error");

	if (std::floor(num) != num || num > 2147483647 || num < 0)
	   throw std::invalid_argument("Error");
}

void PmergeMe::pushNums(const char** argv)
{
	double num;
	char* ptr;

	for (std::size_t i = 1; argv[i]; ++i)
	{
		num = std::strtod(argv[i], &ptr);

		parseInput(num, ptr, argv[i]);

		this->originalData.push_back(static_cast<int>(num));
	}
}

void PmergeMe::pushVecs(intVec2D& vec2D) const
{
	for (std::size_t i = 0; i < originalData.size(); ++i)
	{
		std::vector<int> elementVec;
		
		elementVec.push_back(originalData[i]);
		vec2D.push_back(elementVec);
	}
}

void PmergeMe::FJSort()
{
	intVec2D mainChainVec;

	pushVecs(mainChainVec);
	FJSortVec(mainChainVec);
	getSortedVec(mainChainVec);

	if (std::is_sorted(vec.begin(), vec.end()) == true)
		std::cout << "true!" << std::endl;
	else
		std::cout << "false" << std::endl;
}

PmergeMe::intVec2D PmergeMe::FJSortVec(intVec2D& mainChain) const
{
	intVec2D rest;

	if (mainChain.size() > 3)
		splitChain(mainChain, rest);

	if (mainChain.size() > 3)
		mainChain = FJSortVec(mainChain);
	else
		std::sort(mainChain.begin(), mainChain.end());

	if (rest.empty() == false)
		binaryInsert(mainChain, rest);

	return (mainChain);
}

void PmergeMe::splitChain(intVec2D& mainChain, intVec2D& rest) const
{
	intVec2D newMainChain;
	std::size_t i = 0;
	std::size_t j = 0;

	while (i < mainChain.size() - 1)
	{
		if (mainChain[i][0] <= mainChain[i + 1][0])
		{
			newMainChain.push_back(mainChain[i + 1]);
			rest.push_back(mainChain[i]);
			newMainChain[j].push_back(j);
		}
		else
		{
			newMainChain.push_back(mainChain[i]);
			rest.push_back(mainChain[i + 1]);
			newMainChain[j].push_back(j);
		}

		++j;
		i += 2;
		if (i == mainChain.size() - 1)
			rest.push_back(mainChain[i]);
	}

	mainChain = newMainChain;
}

void PmergeMe::binaryInsert(intVec2D& mainChain, intVec2D& rest) const
{
	std::vector<std::size_t> restIndex;
	std::vector<std::size_t> Jacobs;

	moveIndex(mainChain, rest, restIndex);

	makeJacobsNums(Jacobs, restIndex);

	int high = 1;
	for (std::size_t i = 0; i < Jacobs.size(); ++i)
	{

		for (std::size_t j = Jacobs[i] - 1; i == 0 || j > Jacobs[i - 1] - 1; --j)
		{
			mainChain.insert(mainChain.begin() + 
					binarySearch(mainChain, rest[restIndex[j]][0], high - 1), 
					rest[restIndex[j]]);
			if (!i)
				break ;
		}

		high = high * 2 + 1;
		if (high > static_cast<int>(mainChain.size()))
			high = static_cast<int>(mainChain.size());
	}
}

int PmergeMe::binarySearch(intVec2D& mainChain, int restValue, int high) const
{
	int low = 0;
	int mid;

	mid = low + (high - low) / 2;
	while (low < high)
	{
		if (mainChain[mid][0] > restValue)
			high = mid - 1;
		else if (mainChain[mid][0] < restValue)
			low = mid + 1;
		else
			break ;

		mid = low + (high - low) / 2;
	}

	if (mainChain[mid][0] >= restValue)
		return (mid);
	else
		return (mid + 1);
}

void PmergeMe::moveIndex(intVec2D& mainChain, intVec2D& rest, 
		std::vector<std::size_t>& restIndex) const
{
	for (std::size_t i = 0; i < mainChain.size(); ++i)
	{
		restIndex.push_back(mainChain[i].back());
		mainChain[i].pop_back();
	}

	if (restIndex.size() != rest.size())
		restIndex.push_back(rest.size() - 1);
}

void PmergeMe::makeJacobsNums(std::vector<std::size_t>& Jacobs, 
		std::vector<std::size_t>& restIndex) const
{
	Jacobs.push_back(1);
	if (restIndex.size() > 1)
		Jacobs.push_back(3);
	else
		return ;

	int n = 2;
	while (Jacobs.back() < restIndex.size())
	{
		Jacobs.push_back(Jacobs[n - 1] + 2 * Jacobs[n - 2]);
		++n;
	}

	Jacobs.back() = restIndex.size();
}

void PmergeMe::getSortedVec(intVec2D& mainChain)
{
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		this->vec.push_back(mainChain[i][0]);
}

void PmergeMe::print2DVec(intVec2D vec) const
{
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		for (std::size_t j = 0; j < vec[i].size(); ++j)
			std::cout << vec[i][j] << " ";

		std::cout << "    ";
	}

	std::cout << std::endl;
}
