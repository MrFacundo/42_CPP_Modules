/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:55 by facu              #+#    #+#             */
/*   Updated: 2023/12/26 15:37:29 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie created" << std::endl;
}


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
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::addName(const std::string& name)
{
	this->name = name;
}

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].addName(name);
	return (horde);
}