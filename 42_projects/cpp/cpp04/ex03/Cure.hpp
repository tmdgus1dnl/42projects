/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:41 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 15:08:36 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	private :
		Cure(const Cure& other);

	public :
		Cure();
		Cure& operator=(const Cure& other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};
