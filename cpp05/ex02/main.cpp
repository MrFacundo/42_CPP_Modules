/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 16:41:50 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Test " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

template<typename FormType>
void testCopyConstructor(std::string testName)
{
	printTitle(testName);
	std::cout << "TEST1" << std::endl;
	FormType a("a");
	Bureaucrat b("b", 70);
	b.signForm(a);
	FormType c(a);
	std::cout << a << std::endl;
	std::cout << c << std::endl;
}

template<typename FormType>
void	testExecute(std::string testName)
{
	printTitle(testName);
	std::cout << "TEST1" << std::endl;
	FormType a("a");
	Bureaucrat b("b", 1);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.executeForm(a);
	
	std::cout << "TEST2" << std::endl;
	b.signForm(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.executeForm(a);
	
	std::cout << "TEST3" << std::endl;
	Bureaucrat c("c", 137);
	std::cout << c << std::endl;
	c.executeForm(a);
}

int main(void)
{
	testCopyConstructor<ShrubberyCreationForm>("Copy Constructor with ShrubberyCreationForm");
	testExecute<ShrubberyCreationForm>("Execute with ShrubberyCreationForm");
	testCopyConstructor<RobotomyRequestForm>("Copy Constructor with RobotomyRequestForm");
	testExecute<RobotomyRequestForm>("Execute with RobotomyRequestForm");
	testCopyConstructor<PresidentialPardonForm>("Copy Constructor with PresidentialPardonForm");
	testExecute<PresidentialPardonForm>("Execute with PresidentialPardonForm");
	return (0);
}