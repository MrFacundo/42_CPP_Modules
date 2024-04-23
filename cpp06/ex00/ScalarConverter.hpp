/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:06:41 by facu              #+#    #+#             */
/*   Updated: 2024/04/22 20:27:34 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>


enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};


class ScalarConverter {

	private:
		// CONSTRUCTORS AND DESTRUCTORS
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		// OPERATORS
		ScalarConverter& operator=(ScalarConverter const &rhs);
		// MEMBER FUNCTIONS
		static void printChar(const char c);
		static void printInt(const int i);
		static void printFloat(const float f);
		static void printDouble(const double d);

		static char stringToChar(std::string const &literal);
		static int stringToInt(std::string const &literal);
		static float stringToFloat(std::string const &literal);
		static double stringToDouble(std::string const &literal);
	public:
		// MEMBER FUNCTIONS
		static void convert(std::string literal);
};

#endif