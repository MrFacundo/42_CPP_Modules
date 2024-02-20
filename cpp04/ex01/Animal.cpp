/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:11 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/18 23:40:18 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Generic animal sounds" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::printType(void) const
{
	std::cout << "I'm a " << this->type << std::endl;
}