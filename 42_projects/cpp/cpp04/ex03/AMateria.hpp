/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:06:27 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Floor.hpp"

class ICharacter;

class AMateria
{
	protected :
		std::string type;
		AMateria();
		AMateria(const AMateria& other);

	public :
		AMateria(std::string const & type);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
