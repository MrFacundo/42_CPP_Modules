/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:17 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/18 23:44:08 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal(void);
		AAnimal &operator=(const AAnimal &rhs);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		void printType(void) const;
};

#endif