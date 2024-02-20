/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:26 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/14 18:37:31 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

