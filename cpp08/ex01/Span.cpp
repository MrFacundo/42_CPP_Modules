/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:31:26 by facu              #+#    #+#             */
/*   Updated: 2024/05/04 16:19:56 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Span::Span(void) : size(0) {}

Span::Span(unsigned int size) : size(size) 
{
	/* 
		Prevents the vector from reallocating memory every time a new element is added
		but allocates memory for the maximum number of elements that the vector can store.
	*/
	numbers.reserve(size);
}

Span::Span(Span const &src) : size(src.size), numbers(src.numbers) {}

Span::~Span(void) {}

// OPERATORS
Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		if(this->size != rhs.size)
			throw InvalidAssignmentException();
		this->numbers = rhs.numbers;
	}
	return *this;
}

// GETTERS
unsigned int Span::getSize(void) const
{
	return this->size;
}

// MEMBER FUNCTIONS
void	Span::addNumber(int n)
{
	try 
	{
		if (this->numbers.size() == this->size)
			throw FullContainerException();
		this->numbers.push_back(n);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		if (this->numbers.size() + std::distance(begin, end) > this->size)
			throw FullContainerException();
		this->numbers.insert(this->numbers.end(), begin, end);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int	Span::shortestSpan(void)
{
	if (this->numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = this->numbers;
	std::sort(sorted.begin(), sorted.end());
	int min_span = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1] - sorted[i] < min_span)
			min_span = sorted[i + 1] - sorted[i];
	}
	return min_span;
}

int Span::longestSpan(void)
{
	if (this->numbers.size() < 2)
		throw Span::NoSpanException();
	std::vector<int> sorted = this->numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}

// EXCEPTIONS
const char *Span::FullContainerException::what() const throw()
{
	return "Container is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "No span to find";
}

const char *Span::InvalidAssignmentException::what() const throw()
{
	return "Cannot assign spans of different sizes";
}