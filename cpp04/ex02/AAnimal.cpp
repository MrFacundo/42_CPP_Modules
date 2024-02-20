/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:11 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/18 23:40:18 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	this->type = rhs.type;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}

void AAnimal::printType(void) const
{
	std::cout << "I'm a " << this->type << std::endl;
}