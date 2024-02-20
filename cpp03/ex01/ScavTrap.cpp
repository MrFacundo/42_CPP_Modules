/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:53:23 by facu              #+#    #+#             */
/*   Updated: 2024/02/15 17:37:44 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// CONSTRUCTORS AND DESTRUCTORS

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap std::string constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// OPERATORS

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

// MEMBER FUNCTIONS

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->energyPoints < 1)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	this->energyPoints = this->energyPoints - 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
