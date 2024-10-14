/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/13 19:10:23 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
		typedef std::vector< std::vector<int> > Vec2D;
		typedef std::list< std::list<int> > Lst2D;
		typedef std::list< std::list<int> >::iterator lst2D_it;
		typedef std::list<int>::iterator lst_it;
		typedef std::list<std::size_t>::iterator Tlst_it;
		PmergeMe(const char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void parseInput(double num, const char* ptr, const char* str) const;
		void pushNums(const char** argv);
		void FJSort();
		void pushVecs(Vec2D& vec2D) const;
		void pushLsts(Lst2D& lst2D) const;
		void splitChain(Vec2D& mainChain, Vec2D& rest) const;
		void splitChain(Lst2D& mainChain, Lst2D& rest) const;
		void binaryInsert(Vec2D& mainChain, Vec2D& rest) const;
		void binaryInsert(Lst2D& mainChain, Lst2D& rest) const;
		void moveIndex(Vec2D& mainChain, Vec2D& rest, 
				std::vector<std::size_t>& restIndex) const;
		void moveIndex(Lst2D& mainChain, Lst2D& rest, 
				std::list<std::size_t>& restIndex) const;
		void makeJacobsNums(std::vector<std::size_t>& Jacobs, 
				std::vector<size_t>& restIndex) const;
		void makeJacobsNums(std::list<std::size_t>& Jacobs, 
				std::list<size_t>& restIndex) const;
		void getSortedVec(Vec2D& mainChain);
		void getSortedLst(Lst2D& mainChain);
		void printBefore() const;
		void printAfter() const;
		void printTimeSpent(clock_t timeSpent, std::string container) const;
		int binarySearch(Vec2D& mainChain, int restValue, int high) const;
		int binarySearch(Lst2D& mainChain, int restValue, int high) const;
		Vec2D FJSortVec(Vec2D& mainChain) const;
		Lst2D FJSortLst(Lst2D& mainChain) const;
		lst2D_it getRest_it(Lst2D& rest, std::list<std::size_t> restIndex, 
				std::size_t j) const;
		Tlst_it getPrevIt(Tlst_it it, int n) const;
		Tlst_it getNextIt(Tlst_it it, int n) const;
		lst2D_it getNextIt(lst2D_it it, int n) const;
		const std::vector<int>& getData() const;
		const std::vector<int>& getVec() const;
		const std::list<int>& getLst() const;
};
