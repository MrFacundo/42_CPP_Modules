/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:08:16 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/15 17:30:58 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// CONSTRUCTORS AND DESTRUCTORS

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap std::string constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// OPERATORS

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

// MEMBER FUNCTIONS

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " points of energy left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of health!" << std::endl;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hitPoints left!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " points of energy left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " points of health left!" << std::endl;
}
