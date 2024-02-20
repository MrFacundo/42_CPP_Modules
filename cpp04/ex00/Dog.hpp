/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:32 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/18 23:43:40 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);
		Dog &operator=(const Dog &rhs);
		void makeSound(void) const;
};

#endif