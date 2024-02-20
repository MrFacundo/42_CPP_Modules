/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:19 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/19 18:09:32 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    if (src.brain != NULL)
        this->brain = new Brain(*(src.brain));
    else
        this->brain = NULL;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		Cat temp(rhs);
		std::swap(this->type, temp.type);
		std::swap(this->brain, temp.brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

void Cat::printIdeas(void) const
{
	this->brain->printIdeas();
}

void Cat::setIdea(int index, std::string idea)
{
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return this->brain->getIdea(index);
}
