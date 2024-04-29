/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:05:21 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 18:55:38 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstring>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int _size;
	
	public:
		// CONSTUCTORS / DESTRUCTORS
		Array(void) : array(0), _size(0) {}
		Array(unsigned int n) : array(new T[n]), _size(n) { bzero(array, sizeof(T) * n); }
		Array(Array const & src) : array(0), _size(0) { *this = src; }
		~Array(void) { delete [] array; }

		// OPERATORS
		Array &operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				if (array)
					delete [] array;
				array = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					array[i] = rhs.array[i];
				_size = rhs._size;
			}
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return array[i];
		}

		// GETTERS AND SETTERS
		unsigned int size(void) const { return _size; }

		// MEMBER FUNCTIONS
		void	print(void) const
		{
			for (unsigned int i = 0; i < _size; i++)
				std::cout << array[i] << std::endl;
		}
};

#endif