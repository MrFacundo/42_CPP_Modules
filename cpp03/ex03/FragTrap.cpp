/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:57:12 by facu              #+#    #+#             */
/*   Updated: 2024/02/15 17:52:43 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// CONSTRUCTORS AND DESTRUCTORS

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap std::string constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// OPERATORS

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

// MEMBER FUNCTIONS

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " is requesting a high five" << std::endl;
}