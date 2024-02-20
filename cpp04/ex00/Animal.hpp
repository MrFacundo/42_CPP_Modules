/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:17 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/20 15:05:04 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &src);
		virtual ~Animal(void);
		Animal &operator=(const Animal &rhs);
		virtual void makeSound(void) const;
		std::string getType(void) const;
		void printType(void) const;
};

#endif