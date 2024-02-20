/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:32 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:27 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(const Dog &src);
		virtual ~Dog(void);
		Dog &operator=(const Dog &rhs);
		void makeSound(void) const;
		void printIdeas(void) const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif