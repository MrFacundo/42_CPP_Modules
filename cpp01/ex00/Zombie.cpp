/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:55 by facu              #+#    #+#             */
/*   Updated: 2023/12/26 12:40:25 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name)
{
	std::cout << name << " created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}