/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:51:53 by facu              #+#    #+#             */
/*   Updated: 2024/04/23 18:29:43 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer::~Serializer(void) {}

// OPERATORS
Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return *this;
}

// MEMBER FUNCTIONS
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}