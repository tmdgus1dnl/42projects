/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:56:06 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/27 17:45:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract_bits(8);

Fixed::Fixed()
{
	this->fixed_value = 0;
}

Fixed::Fixed(const int i_value)
{
	this->fixed_value = i_value << this->fract_bits;
}

Fixed::Fixed(const float f_value)
{
	this->fixed_value = roundf(f_value * (1 << this->fract_bits));
}


Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

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

//comparison

bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

//arithmetic

float Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat());
}

float Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat());
}

float Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

float Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

//in/decrement

Fixed& Fixed::operator++()
{
	(this->fixed_value)++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed temp(*this);

	(this->fixed_value)++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	(this->fixed_value)--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	const Fixed temp(*this);

	(this->fixed_value)--;
	return (temp);
}

//max/min

Fixed& Fixed::min(Fixed& x, Fixed& y)
{
	if (x >= y)
		return (y);
	return (x);
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y)
{
	if (x >= y)
		return (y);
	return (x);
}

Fixed& Fixed::max(Fixed& x, Fixed& y)
{
	if (x >= y)
		return (x);
	return (y);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y)
{
	if (x >= y)
		return (x);
	return (y);
}
