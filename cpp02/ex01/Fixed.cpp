/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:48 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/02 16:57:35 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
	return (*this);
}

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

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}