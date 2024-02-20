/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:04:29 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/01 16:07:36 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int                 fixedPointValue;
		static const int    fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed &operator=(const Fixed &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif