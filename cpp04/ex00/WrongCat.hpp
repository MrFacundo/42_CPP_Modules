/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:08:23 by facu              #+#    #+#             */
/*   Updated: 2024/02/18 11:17:27 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongWRONGCAT_HPP
# define WrongWRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);
		WrongCat &operator=(const WrongCat &rhs);
		void makeSound(void) const;
};

#endif