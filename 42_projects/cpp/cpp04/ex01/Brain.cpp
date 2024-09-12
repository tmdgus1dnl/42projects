/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:58:38 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 15:09:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty";
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy created" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		this->mindset(other);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain is gone" << std::endl;
}

void Brain::mindset(std::string idea)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = idea;
}

void Brain::mindset(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		(this->ideas)[i] = (other.ideas)[i];
}

const std::string Brain::getIdea() const
{
	return (ideas[50]);
}
