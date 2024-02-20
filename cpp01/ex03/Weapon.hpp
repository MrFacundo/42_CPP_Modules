/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:23:52 by facu              #+#    #+#             */
/*   Updated: 2023/12/28 13:22:55 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		std::string const &getType(void);
		void setType(std::string type);
};

#endif