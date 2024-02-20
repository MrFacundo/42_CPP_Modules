/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/15 17:44:54 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap scav_default;
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");
	
	scav_default.takeDamage(10);
	scav_default.attack("enemy");
	clap.attack("enemy");
	scav.attack("enemy");
	clap.takeDamage(10);
	scav.takeDamage(10);
	clap.beRepaired(10);
	scav.beRepaired(10);
	scav.guardGate();
	scav_default = scav;
	return (0);
}