/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:19:36 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/12 15:51:05 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &src);
		~Point(void);
		Point &operator=(const Point &rhs);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif