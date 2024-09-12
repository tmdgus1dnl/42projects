/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:34:14 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/04 13:19:55 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Floor
{
	private :
		AMateria* floor[4];
		Floor();
		Floor(const Floor& other);
		Floor& operator=(const Floor& other);

	public :
		~Floor();
		static Floor& getInstance();
		AMateria* pickupMateria();
		void dropMateria(AMateria* m);
		void empty_func() const;
};
