/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/15 17:32:17 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap clapTrap_default;
	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3 = clapTrap;

	clapTrap_default.attack("enemy");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	return 0;
}