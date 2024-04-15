/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 17:45:26 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Test " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void	testFormCreation(std::string testName, std::string formName, std::string target)
{
	printTitle(testName);
	Intern intern;
	AForm* form = intern.makeForm(formName, target);
	if (form)
		std::cout << *form << std::endl;
	delete form;
}

int main(void)
{
	testFormCreation("form creation", "shrubbery creation", "home");
	testFormCreation("form creation", "robotomy request", "home");
	testFormCreation("form creation", "presidential pardon", "home");
	testFormCreation("form creation", "invalid form", "home");
	return (0);
}