/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:34:12 by facu              #+#    #+#             */
/*   Updated: 2023/12/27 20:22:03 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}