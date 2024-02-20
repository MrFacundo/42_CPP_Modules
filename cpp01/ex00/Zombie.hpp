/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:59 by facu              #+#    #+#             */
/*   Updated: 2023/12/26 12:46:52 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie(void);
		void    announce(void);

	private:
		std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif