/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:10:04 by facu              #+#    #+#             */
/*   Updated: 2024/02/18 11:34:38 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongANIMAL_HPP
# define WrongANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		void makeSound(void) const;
		std::string getType(void) const;
		void printType(void) const;
};

#endif