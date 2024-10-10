/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/10 19:15:22 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <exception>

class PmergeMe
{
	private :
		std::vector<int> originalData;
		std::vector<int> vec;
		std::list<int> lst;
		PmergeMe();

	public :
		typedef std::vector< std::vector<int> > intVec2D;
		typedef std::list<int>::iterator lst_it;
		PmergeMe(const char** argv);
		/*PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);*/
		~PmergeMe();
		void pushNums(const char** argv);
		void FJSort();
		void pushVecs(intVec2D& vec2D) const;
		void parseInput(double num, const char* ptr, const char* str) const;
		void splitChain(intVec2D& mainChain, intVec2D& rest) const;
		void binaryInsert(intVec2D& mainChain, intVec2D& rest) const;
		void moveIndex(intVec2D& mainChain, intVec2D& rest, 
				std::vector<std::size_t>& restIndex) const;
		void makeJacobsNums(std::vector<std::size_t>& Jacobs, 
				std::vector<size_t>& restIndex) const;
		void getSortedVec(intVec2D& mainChain);
		void print2DVec(intVec2D vec) const;
		int binarySearch(intVec2D& mainChain, int restValue, int high) const;
		intVec2D FJSortVec(intVec2D& mainChain) const;
};
