/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:06:27 by facu              #+#    #+#             */
/*   Updated: 2024/02/18 11:54:50 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.type;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Generic wrong animal sounds" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::printType(void) const
{
	std::cout << "I'm a " << this->type << std::endl;
}

