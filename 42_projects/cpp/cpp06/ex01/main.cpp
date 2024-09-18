/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:10:18 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 12:21:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	Data* ptr = NULL;
	uintptr_t intAddress;

	data.value = 3;

	std::cout << "data value : " << data.value << std::endl;
	std::cout << "dataAddress : " << &data << std::endl;

	intAddress = Serializer::serialize(&data);
	std::cout << "dataAddress to int : " << intAddress << std::endl;

	ptr = Serializer::deserialize(intAddress);
	if (ptr)
	{
		std::cout << "intAddress to data* : " << ptr << std::endl;
		std::cout << "data* value : " << ptr->value << std::endl;
	}

	return (0);
}
