/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/15 18:24:37 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap diamond("DiamondTrap");
	DiamondTrap diamond2(diamond);

	diamond.whoAmI();
	diamond2.whoAmI();

	diamond.beRepaired(10);
	diamond.takeDamage(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.attack("enemy");

	diamond2.beRepaired(10);
	diamond2.takeDamage(10);
	diamond2.guardGate();
	diamond2.highFivesGuys();
	diamond2.attack("enemy");

	return (0);
}