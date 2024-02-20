/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:24:59 by facu              #+#    #+#             */
/*   Updated: 2023/12/27 19:33:44 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}