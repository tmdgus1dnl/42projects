/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:57:15 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:28 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private :
		Ice(const Ice& other);

	public :
		Ice();
		Ice& operator=(const Ice& other);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};
