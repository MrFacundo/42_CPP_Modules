/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:34:30 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/15 17:56:13 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTORS AND DESTRUCTORS

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "default";
	ClapTrap::name = "default_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap std::string constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// OPERATORS

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->name = rhs.name;
	ClapTrap::name = rhs.ClapTrap::name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return *this;
}

// MEMBER FUNCTIONS

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->name << " and my ClapTrap name is " <<  ClapTrap::name << std::endl;
}
