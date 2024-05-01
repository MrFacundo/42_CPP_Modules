/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:47:22 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 16:55:46 by ftroiter         ###   ########.fr       */
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
AForm *Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
	typedef AForm *(Intern::*FormCreator)(std::string const &);

	FormCreator formCreators[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw Intern::InvalidFormName();
}


// EXCEPTIONS
const char* Intern::InvalidFormName::what(void) const throw() {
	return "Invalid form name";
}