/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:48 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/01 17:04:43 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
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
