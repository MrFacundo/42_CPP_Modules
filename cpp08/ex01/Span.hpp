/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:10:41 by facu              #+#    #+#             */
/*   Updated: 2024/05/04 16:19:43 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int const size;
		std::vector<int> numbers;
		// CONSTRUCTORS AND DESTRUCTORS
		Span(void);
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Span(unsigned int size);
		Span(Span const &src);
		~Span(void);
		// OPERATORS
		Span &operator=(Span const &rhs);
		// GETTERS
		unsigned int getSize(void) const;
		// MEMBER FUNCTIONS
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
		// EXCEPTIONS
		class FullContainerException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class InvalidAssignmentException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif