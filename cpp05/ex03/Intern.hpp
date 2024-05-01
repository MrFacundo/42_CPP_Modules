/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:25:42 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 16:54:38 by ftroiter         ###   ########.fr       */
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
		AForm* createShrubberyCreationForm(std::string const &target);
		AForm* createRobotomyRequestForm(std::string const &target);
		AForm* createPresidentialPardonForm(std::string const &target);
		AForm* makeForm(std::string name, std::string target);
		// EXCEPTIONS
		class InvalidFormName : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif