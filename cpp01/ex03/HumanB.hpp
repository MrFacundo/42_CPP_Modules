/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:21 by facu              #+#    #+#             */
/*   Updated: 2023/12/27 20:25:08 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif