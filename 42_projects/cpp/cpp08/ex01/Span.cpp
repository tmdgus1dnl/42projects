/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:46:14 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 15:54:30 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	size = N;
}

Span::~Span() {}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->size = other.getSize();
		vec.resize(other.getVec().size());
		std::copy(other.getVec().begin(), other.getVec().end(), (this->vec).begin());
		std::sort(vec.begin(), vec.end());
	}
	return (*this);
}

void Span::addNumber(int value)
{
	if (vec.size() >= this->size)
		throw std::exception();
	vec.push_back(value);
	std::sort(vec.begin(), vec.end());
}

long Span::shortestSpan()
{
	if (vec.size() <= 1)
		throw std::exception();

	std::vector<int> diff_vec(vec.size());
	long diff;

	std::adjacent_difference(vec.begin(), vec.end(), diff_vec.begin());
	diff = diff_vec[1];

	for (std::size_t i = 1; i < diff_vec.size(); ++i)
	{
		if (diff_vec[i] < diff)
			diff = diff_vec[i];
	}

	return (diff);
}

long Span::longestSpan()
{
	if (vec.size() <= 1)
		throw std::exception();
	return (vec.back() - vec.front());
}

std::size_t Span::getSize() const
{
	return (size);
}

const std::vector<int>& Span::getVec() const
{
	return (vec);
}
