/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:06:14 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/15 17:31:43 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &rhs);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif