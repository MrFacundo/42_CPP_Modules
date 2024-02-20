/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:21 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:20 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include <utility>

class Cat : public Animal
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