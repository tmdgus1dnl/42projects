/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/03 16:01:07 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <exception>

class PmergeMe
{
	private :
		std::vector<int> vec;
		std::list<int> lst;
		PmergeMe();

	public :
		typedef std::list<int>::iterator lst_it;
		PmergeMe(const char** argv);
		/*PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);*/
		~PmergeMe();
		void pushNums(const char** argv);
		void parseInput(double num, const char* ptr, const char* str) const;
		void FJSort();
		void printCont(const std::string& Contname);
};
