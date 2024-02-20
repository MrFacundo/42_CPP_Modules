/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:26 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:38 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    if (src.brain != NULL)
        this->brain = new Brain(*(src.brain));
    else
        this->brain = NULL;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		Dog temp(rhs);
		std::swap(this->type, temp.type);
		std::swap(this->brain, temp.brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

void Dog::printIdeas(void) const
{
	this->brain->printIdeas();
}

void Dog::setIdea(int index, std::string idea)
{
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return this->brain->getIdea(index);
}