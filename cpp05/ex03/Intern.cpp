/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:47:22 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 17:44:38 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

// OPERATORS
Intern &Intern::operator=(Intern const &rhs) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &rhs) {
	}
	return *this;
}

// MEMBER FUNCTIONS
AForm* Intern::makeForm(std::string name, std::string target) {
	try
	{
		AForm* forms[] = {
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)
		};

		std::string formNames[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};

		for (int i = 0; i < 3; i++) {
			if (name == formNames[i]) {
				std::cout << "Intern creates " << name << std::endl;
				return forms[i];
			}
			delete forms[i];
		}
		throw Intern::InvalidFormName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

// EXCEPTIONS
const char* Intern::InvalidFormName::what(void) const throw() {
	return "Invalid form name";
}