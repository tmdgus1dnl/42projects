/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/14 15:58:10 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char** argv)
{
	pushNums(argv);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->originalData = other.getData();
		this->vec = other.getVec();
		this->lst = other.getLst();
	}
	
	return (*this);
}

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

void PmergeMe::pushVecs(Vec2D& vec2D) const
{
	for (std::size_t i = 0; i < originalData.size(); ++i)
	{
		std::vector<int> elementVec;
		
		elementVec.push_back(originalData[i]);
		vec2D.push_back(elementVec);
	}
}

void PmergeMe::pushLsts(Lst2D& lst2D) const
{
	for (std::size_t i = 0; i < originalData.size(); ++i)
	{
		std::list<int> elementLst;
		
		elementLst.push_back(originalData[i]);
		lst2D.push_back(elementLst);
	}
}

void PmergeMe::FJSort()
{
	Vec2D mainChainVec;
	Lst2D mainChainLst;
	clock_t start, end;

	printBefore();

	pushVecs(mainChainVec);
	start = clock();
	FJSortVec(mainChainVec);
	getSortedVec(mainChainVec);
	end = clock();

	printAfter();
	printTimeSpent(end - start, "vector");

	pushLsts(mainChainLst);
	start = clock();
	FJSortLst(mainChainLst);
	getSortedLst(mainChainLst);
	end = clock();

	printTimeSpent(end - start, "list");
}

PmergeMe::Vec2D PmergeMe::FJSortVec(Vec2D& mainChain) const
{
	Vec2D rest;

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

PmergeMe::Lst2D PmergeMe::FJSortLst(Lst2D& mainChain) const
{
	Lst2D rest;

	if (mainChain.size() > 3)
		splitChain(mainChain, rest);

	if (mainChain.size() > 3)
		mainChain = FJSortLst(mainChain);
	else
		mainChain.sort();

	if (rest.empty() == false)
		binaryInsert(mainChain, rest);

	return (mainChain);
}

void PmergeMe::splitChain(Vec2D& mainChain, Vec2D& rest) const
{
	Vec2D newMainChain;
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

void PmergeMe::splitChain(Lst2D& mainChain, Lst2D& rest) const
{
	Lst2D newMainChain;
	lst2D_it main_it = mainChain.begin();
	lst2D_it newMain_it;
	lst2D_it nextMain_it;
	std::size_t j = 0;

	while (main_it != mainChain.end() && main_it != --(mainChain.end()))
	{
		nextMain_it = getNextIt(main_it, 1);

		if (*(main_it->begin()) <= *(nextMain_it->begin()))
		{
			newMainChain.push_back(*nextMain_it);
			rest.push_back(*main_it);
		}
		else
		{
			newMainChain.push_back(*main_it);
			rest.push_back(*nextMain_it);
		}

		if (!j)
			newMain_it = newMainChain.begin();
		else
			++newMain_it;

		newMain_it->push_back(j);
		++j;
		std::advance(main_it, 2);
		if (main_it == --(mainChain.end()))
			rest.push_back(*main_it);
	}

	mainChain = newMainChain;
}

void PmergeMe::binaryInsert(Vec2D& mainChain, Vec2D& rest) const
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

void PmergeMe::binaryInsert(Lst2D& mainChain, Lst2D& rest) const
{
	std::list<std::size_t> restIndex;
	std::list<std::size_t> Jacobs;

	moveIndex(mainChain, rest, restIndex);

	makeJacobsNums(Jacobs, restIndex);

	int high = 1;
	for (Tlst_it J_it = Jacobs.begin(); J_it != Jacobs.end(); ++J_it)
	{

		for (std::size_t j = *J_it - 1; J_it == Jacobs.begin() || 
				j > *(getPrevIt(J_it, 1)) - 1; --j)
		{
			lst2D_it main_it = mainChain.begin();
			std::advance(main_it, binarySearch(mainChain, 
						*(getRest_it(rest, restIndex, j)->begin()), high - 1));
			mainChain.insert(main_it, *(getRest_it(rest, restIndex, j)));

			if (J_it == Jacobs.begin())
				break ;
		}

		high = high * 2 + 1;
		if (high > static_cast<int>(mainChain.size()))
			high = static_cast<int>(mainChain.size());
	}
}

int PmergeMe::binarySearch(Vec2D& mainChain, int restValue, int high) const
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

int PmergeMe::binarySearch(Lst2D& mainChain, int restValue, int high) const
{
	lst2D_it main_it;
	int low = 0;
	int mid;

	mid = low + (high - low) / 2;
	while (low < high)
	{
		main_it = getNextIt(mainChain.begin(), mid);

		if (*(main_it->begin()) > restValue)
			high = mid - 1;
		else if (*(main_it->begin()) < restValue)
			low = mid + 1;
		else
			break ;

		mid = low + (high - low) / 2;
	}
	main_it = getNextIt(mainChain.begin(), mid);

	if (*(main_it->begin()) >= restValue)
		return (mid);
	else
		return (mid + 1);
}

void PmergeMe::moveIndex(Vec2D& mainChain, Vec2D& rest, 
		std::vector<std::size_t>& restIndex) const
{
	for (std::size_t i = 0; i < mainChain.size(); ++i)
	{
		restIndex.push_back(mainChain[i].back());
		mainChain[i].pop_back();
	}

	if (restIndex.size() != rest.size())
		restIndex.push_back(rest.size() - 1); // 나머지 요소가 존재할때
											  // 나머지 요쇼 인덱스 삽입
}

void PmergeMe::moveIndex(Lst2D& mainChain, Lst2D& rest, 
		std::list<std::size_t>& restIndex) const
{
	for (lst2D_it main_it = mainChain.begin(); main_it != mainChain.end(); ++main_it)
	{
		restIndex.push_back(main_it->back());
		main_it->pop_back();
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

	for (int n = 2; Jacobs.back() < restIndex.size(); ++n)
		Jacobs.push_back(Jacobs[n - 1] + 2 * Jacobs[n - 2]);

	Jacobs.back() = restIndex.size();

}

void PmergeMe::makeJacobsNums(std::list<std::size_t>& Jacobs, 
		std::list<std::size_t>& restIndex) const
{
	Jacobs.push_back(1);
	if (restIndex.size() > 1)
		Jacobs.push_back(3);
	else
		return ;

	Tlst_it J_it = Jacobs.begin();
	std::advance(J_it, 2);

	while (Jacobs.back() < restIndex.size())
		Jacobs.push_back(*(getPrevIt(J_it, 1)) + 2 * *(getPrevIt(J_it, 2)));

	Jacobs.back() = restIndex.size();

}

PmergeMe::lst2D_it PmergeMe::getRest_it(Lst2D& rest, 
		std::list<std::size_t> restIndex, std::size_t j) const
{
	Tlst_it restIndex_it = getNextIt(restIndex.begin(), j);

	return (getNextIt(rest.begin(), *restIndex_it));
}

PmergeMe::lst2D_it PmergeMe::getNextIt(lst2D_it it, int n) const
{
	for (int i = 0; i < n; ++i)
		++it;

	return (it);
}

PmergeMe::Tlst_it PmergeMe::getNextIt(Tlst_it it, int n) const
{
	for (int i = 0; i < n; ++i)
		++it;

	return (it);
}

PmergeMe::Tlst_it PmergeMe::getPrevIt(Tlst_it it, int n) const
{
	for (int i = 0; i < n; ++i)
		--it;

	return (it);
}

void PmergeMe::getSortedVec(Vec2D& mainChain)
{
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		this->vec.push_back(mainChain[i][0]);
}

void PmergeMe::getSortedLst(Lst2D& mainChain)
{
	for (lst2D_it main_it = mainChain.begin(); main_it != mainChain.end(); ++main_it)
		this->lst.push_back(*(main_it->begin()));
}

void PmergeMe::printBefore() const
{
	std::cout << "Before :  ";
	for (std::size_t i = 0; i < originalData.size(); ++i)
		std::cout << originalData[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After :   ";
	for (std::size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printTimeSpent(clock_t timeSpent, std::string container) const
{
	std::cout << "Time to process a range of ";

	if (container == "vector")
		std::cout << std::setw(4) << vec.size() << " elements with std::vector :  ";
	else
		std::cout << std::setw(4) << lst.size() << " elements with std::list :    ";

	double timeSpentMs = static_cast<double>(timeSpent) / CLOCKS_PER_SEC * 1000;

	std::cout << timeSpentMs << " ms" << std::endl;
}

const std::vector<int>& PmergeMe::getData() const
{
	return (this->originalData);
}

const std::vector<int>& PmergeMe::getVec() const
{
	return (this->vec);
}

const std::list<int>& PmergeMe::getLst() const
{
	return (this->lst);
}
