/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:04:29 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/13 14:27:48 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int                 fixedPointValue;
		static const int    fractionalBits = 8;
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);
		// OPERATOR OVERLOADS
		Fixed &operator=(const Fixed &rhs);
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs);
		bool operator<=(const Fixed &rhs);
		bool operator==(const Fixed &rhs);
		bool operator!=(const Fixed &rhs);
		Fixed operator+(const Fixed &rhs);
		Fixed operator-(const Fixed &rhs);
		Fixed operator*(const Fixed &rhs);
		Fixed operator/(const Fixed &rhs);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		// GETTERS AND SETTERS
		int getRawBits(void) const;
		void setRawBits(int const raw);
		// CONVERSION FUNCTIONS
		float toFloat(void) const;
		int toInt(void) const;
		// STATIC FUNCTIONS
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif