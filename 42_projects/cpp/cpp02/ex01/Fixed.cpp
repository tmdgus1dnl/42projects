/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:56:06 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/27 18:10:37 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract_bits(8);

Fixed::Fixed()
{
	this->fixed_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_value = i_value << this->fract_bits;
}

Fixed::Fixed(const float f_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_value = roundf(f_value * (1 << this->fract_bits));
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->fixed_value);
}

int Fixed::toInt() const
{
	return (this->fixed_value >> this->fract_bits);
}

float Fixed::toFloat() const
{
	return ((float)this->fixed_value / (1 << this->fract_bits));
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

std::ostream& operator<<(std::ostream& cout, const Fixed& fixed)
{
	cout << fixed.toFloat();
	return (cout);
}
