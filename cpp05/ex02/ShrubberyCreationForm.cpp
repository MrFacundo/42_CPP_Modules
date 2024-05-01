/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:48:12 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 16:26:41 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS AND DESTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm name, grade constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), target(src.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// OPERATORS
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &rhs)
		target = rhs.target;
	return *this;
}

// MEMBER FUNCTIONS
void ShrubberyCreationForm::executeImpl(const Bureaucrat &executor) const
{
	(void)executor;
	std::ofstream file((std::string(target) + "_shrubbery").c_str(), std::ios::app);	if (!file.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}
	file << "      /\\      \n"
			"     /\\*\\     \n"
			"    /\\O\\*\\    \n"
			"   /*/\\/\\/\\   \n"
			"  /\\O\\/\\*\\/\\  \n"
			" /\\*\\/\\*\\/\\/\\ \n"
			"/\\O\\/\\/*/\\/O/\\\n"
			"      ||      \n"
			"      ||      \n"
			"      ||      \n";
	file.close();
}
