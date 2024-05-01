/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:55:20 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 17:15:35 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const float F_POS_INFINITY = std::numeric_limits<float>::infinity();
const float F_NEG_INFINITY = -std::numeric_limits<float>::infinity();
const double D_POS_INFINITY = std::numeric_limits<double>::infinity();
const double D_NEG_INFINITY = -std::numeric_limits<double>::infinity();

// CONSTRUCTORS AND DESTRUCTORS
ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

// OPERATORS
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

// UTILS
bool isInt(std::string literal)
{
	std::stringstream ss(literal);
	int a;

	ss >> a;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

bool isDouble(std::string literal)
{
	std::stringstream ss(literal);
	double a;

	ss >> a;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

bool isFloat(std::string literal)
{
	if (literal[literal.length() - 1] == 'f')
		literal = literal.erase(literal.length() - 1);

	std::stringstream sstr(literal);
	float a;

	sstr >> a;
	if (!sstr.fail() && sstr.eof())
		return (true);
	return (false);
}

int getType(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return FLOAT;
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return DOUBLE;
	else if (literal.find('.') != std::string::npos)
	{
		if (isDouble(literal))
			return DOUBLE;
		else if (isFloat(literal))
			return FLOAT;
	}
	else if (isInt(literal))
		return INT;
	return INVALID;
}

// MEMBER FUNCTIONS
void ScalarConverter::convert(std::string literal)
{
	int type = getType(literal);

	switch (type)
	{
	case INVALID:
	{
		std::cout << "Invalid input" << std::endl;
		break;
	}
	case CHAR:
	{
		std::cout << "Type: char"  << std::endl;
		char c = stringToChar(literal);
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		break;
	}
	case INT:
	{
		std::cout << "Type: int" << std::endl;
		int i = stringToInt(literal);
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
		break;
	}
	case FLOAT:
	{
		std::cout << "Type: float" << std::endl;
		float f = stringToFloat(literal);
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
		break;
	}
	case DOUBLE:
	{
		std::cout << "Type: double" << std::endl;
		double d = stringToDouble(literal);
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
		break;
	}
	}
}

char ScalarConverter::stringToChar(std::string const &literal)
{
	char c;
	std::istringstream ss(literal);

	ss >> c;
	if (literal[0] == ' ')
		c = ' ';
	return c;
}

int ScalarConverter::stringToInt(std::string const &literal)
{
	int i;
	std::istringstream ss(literal);

	ss >> i;
	return i;
}

float ScalarConverter::stringToFloat(std::string const &literal)
{
	float f;
	std::istringstream ss(literal);

	ss >> f;
	if (ss.fail())
	{
		if (literal == "-inff")
			f = F_NEG_INFINITY;
		else if (literal == "+inff")
			f = F_POS_INFINITY;
		else
			f = std::numeric_limits<float>::quiet_NaN();
	}
	return f;
}

double ScalarConverter::stringToDouble(std::string const &literal)
{
	double d;
	std::istringstream ss(literal);

	ss >> d;
	if (ss.fail())
	{
		if (literal == "-inf")
			d = D_NEG_INFINITY;
		else if (literal == "+inf")
			d = D_POS_INFINITY;
		else
			d = std::numeric_limits<double>::quiet_NaN();
	}
	return d;
}

void ScalarConverter::printChar(const char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(const int i)
{
	std::cout << "int: ";
	std::cout << i << std::endl;
}

void ScalarConverter::printFloat(const float f)
{
	std::cout << "float: ";
	std::cout << f;
	if (f != F_POS_INFINITY && f != F_NEG_INFINITY && (f - floor(f)) <= 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(const double d)
{
	std::cout << "double: ";
	std::cout << d;
	if (d != D_POS_INFINITY && d != D_NEG_INFINITY && (d - floor(d)) <= 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}