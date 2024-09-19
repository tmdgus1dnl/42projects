/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:35:26 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/19 11:20:16 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, std::size_t N>
std::size_t arrSize(T(&)[N])
{
	return (N);
}

template<typename T>
void Print(T& arrElement)
{
	std::cout << arrElement << " ";
}

template <typename T1, typename T2>
void iter(T1* arr, std::size_t length, void (*func)(T2& arrElement))
{
	for (std::size_t i = 0; i < length; ++i)
		func(arr[i]);
	std::cout << std::endl;
}

template <typename T>
void iter(T* arr, std::size_t length, void (*func)(T& arrElement))
{
	for (std::size_t i = 0; i < length; ++i)
		func(arr[i]);
	std::cout << std::endl;
}
