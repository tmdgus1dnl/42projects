/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:05:02 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 11:24:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
	private :
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
