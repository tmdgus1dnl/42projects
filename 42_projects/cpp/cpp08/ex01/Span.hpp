/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:46:47 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 12:25:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <exception>

class Span
{
	private :
		std::vector<int> vec;
		std::size_t size;
		Span();

	public :
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		void addNumber(int value);
		long shortestSpan();
		long longestSpan();
		template <typename T>
		void addAllNumbers(T& container)
		{
			if (vec.size() + container.size() > this->size)
				throw std::exception();
			/*typename T::iterator it = container.begin();
			for (std::size_t i = 0; i < container.size(); ++i)
			{
				if (vec.size() >= this->size)
					throw std::exception();
				vec.push_back(*it);
				it++;
			}*/
			vec.insert(vec.end(), container.begin(), container.end());
			std::sort(vec.begin(), vec.end());
		}
		std::size_t getSize() const;
		const std::vector<int>& getVec() const;
};
