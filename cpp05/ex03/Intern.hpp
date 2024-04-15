/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:25:42 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 18:30:31 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		// OPERATORS
		Intern &operator=(Intern const &rhs);
		// MEMBER FUNCTIONS
		AForm* makeForm(std::string name, std::string target);
		// EXCEPTIONS
		class InvalidFormName : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif