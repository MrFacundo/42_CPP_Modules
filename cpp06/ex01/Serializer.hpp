/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:50:50 by facu              #+#    #+#             */
/*   Updated: 2024/04/23 18:33:11 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cassert>

typedef uintmax_t uintptr_t;

typedef struct Data
{
	int	id;
	int	pid;
	std::string s1;
} Data;

class Serializer {
	
	private:
		// CONSTRUCTORS AND DESTRUCTORS
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);
		// OPERATORS
		Serializer& operator=(Serializer const &rhs);
		// MEMBER FUNCTIONS
	public:
		// MEMBER FUNCTIONS
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif