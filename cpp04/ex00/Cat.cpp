/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:19 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/14 18:37:08 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->type = rhs.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}