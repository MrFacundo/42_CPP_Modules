/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:37:23 by facu              #+#    #+#             */
/*   Updated: 2023/12/27 20:25:08 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::attack(void)
{
    std::cout << this->name << " attacks with ";
    
    if (this->weapon)
    {
        std::cout << "his " << this->weapon->getType();
    }
    else
    {
        std::cout << "no weapon";
    }
    std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}