/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:59 by facu              #+#    #+#             */
/*   Updated: 2023/12/26 15:36:26 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(const std::string& name);
		~Zombie(void);
		void    announce(void);
		void	addName(const std::string& name);

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif