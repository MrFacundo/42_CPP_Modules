/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:52:20 by facu              #+#    #+#             */
/*   Updated: 2024/02/19 00:48:22 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	std::ifstream file("ideas.txt");
	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return;
	}
	std::string line;
	for (int i = 0; i < IdeasSize && std::getline(file, line); ++i)
	{
		ideas[i] = line;
	}
	file.close();
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < IdeasSize; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}

void Brain::printIdeas(void) const
{
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < IdeasSize; i++)
		std::cout << this->ideas[i] << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= IdeasSize)
		return;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= IdeasSize)
		return "";
	return this->ideas[index];
}
