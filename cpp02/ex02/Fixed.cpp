/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:48 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/03 16:20:04 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// CONSTRUCTORS AND DESTRUCTORS

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedPointValue(value << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixedPointValue(roundf(value * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : fixedPointValue(src.fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// GETTERS AND SETTERS

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

// CONVERSION FUNCTIONS

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> fractionalBits);
}

// STATIC FUNCTIONS

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// OPERATOR OVERLOADS

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs)
{
	return (this->fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs)
{
	return (this->fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs)
{
	return (this->fixedPointValue == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs)
{
	return (this->fixedPointValue != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
