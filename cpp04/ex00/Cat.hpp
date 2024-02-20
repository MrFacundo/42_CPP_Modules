/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:21 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/18 23:43:40 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		Cat &operator=(const Cat &rhs);
		void makeSound(void) const;
};

#endif