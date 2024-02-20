/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:04:29 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/02 16:57:55 by ftroiter         ###   ########.fr       */
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
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed &operator=(const Fixed &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		friend std::ostream &operator<<(std::ostream &out, const Fixed &rhs);
};

#endif