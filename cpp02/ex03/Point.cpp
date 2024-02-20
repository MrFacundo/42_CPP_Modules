/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:19:40 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/12 15:47:07 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUCTORS AND DESTRUCTORS

Point::Point(void) : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}
Point::Point(const Point &src) : x(src.x), y(src.y) {}

Point::~Point(void) {}

// OPERATOR OVERLOADS

Point &Point::operator=(const Point &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}

// GETTERS

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}