/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:21:07 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/18 16:31:54 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& max(T& a, T& b)
{
	return (a > b) ? a : b;
}

template <typename T>
T& min(T& a, T& b)
{
	return (a >= b) ? b : a;
}
