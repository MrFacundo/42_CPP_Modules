/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/14 16:57:02 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap frag_default;
	ClapTrap clap("Clap");
	FragTrap frag("frag");
	frag_default = frag;

	frag.attack("enemy");
	frag.takeDamage(10);
	frag.beRepaired(10);
	frag.highFivesGuys();
	return (0);
}