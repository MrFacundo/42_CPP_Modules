/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:21 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/19 18:17:09 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <utility>

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(const Cat &src);
		virtual ~Cat(void);
		Cat &operator=(const Cat &rhs);
		void makeSound(void) const;
		void printIdeas(void) const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif