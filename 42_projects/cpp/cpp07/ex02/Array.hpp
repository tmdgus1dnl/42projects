/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:32:29 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/19 11:08:53 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private :
		T* arr;
		unsigned int len;

	public :
		Array()
		{
			arr = new T[0];
			len = 0;
		}
		Array(unsigned int n)
		{
			arr = new T[n];
			len = n;
		}
		Array(const Array& other)
		{
			this->arr = 0;
			*this = other;
		}
		~Array()
		{
			if (arr)
				delete[] arr;
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				if (this->arr)
					delete[] arr;
				this->len = other.size();
				this->arr = new T[len];
				for (unsigned int i = 0; i < len; ++i)
					(this->arr)[i] = other[i];
			}
			return (*this);
		}
		T& operator[](unsigned int index)
		{
			if (index >= len || index < 0)
				throw std::exception();
			return (arr[index]);
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= len || index < 0)
				throw std::exception();
			return (arr[index]);
		}
		unsigned int size() const
		{
			return (len);
		}
};
