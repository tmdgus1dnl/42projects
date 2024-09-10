/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:45:36 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/28 11:36:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int fixed_value;
		static const int fract_bits;
	
	public :
		Fixed();
		Fixed(const int i_value);
		Fixed(const float f_value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits() const;
		int toInt() const;
		float toFloat() const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& cout, const Fixed& fixed);

#endif
