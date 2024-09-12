/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:58:27 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 14:55:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
	private :
		std::string ideas[100];
		Brain& operator=(const Brain& other);

	public :
		Brain();
		Brain(const Brain& other);
		~Brain();
		void mindset(std::string idea);
		void mindset(const Brain& other);
		const std::string getIdea() const;
};
