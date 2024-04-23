/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 18:20:26 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void testNameAndGradeConstructor(std::string testName)
{
	printTitle(testName);

	std::cout << "TEST1" << std::endl;
	try {
		Bureaucrat a("a", 150);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST2" << std::endl;
	try {
		Bureaucrat b("b", 151);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST3" << std::endl;
	try {
		Bureaucrat c("c", 0);
		std::cout << c << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testCopyConstructor(std::string testName)
{
	printTitle(testName);
	std::cout << "TEST1" << std::endl;
	Bureaucrat a("a", 4);
	Bureaucrat b(a);
	std::cout << b << std::endl;
}

void testIncrementDecrement(std::string testName)
{
	printTitle(testName);
	std::cout << "TEST1" << std::endl;
	Bureaucrat a("a", 4);
	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;

	std::cout << "TEST2" << std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;
	
	std::cout << "TEST3" << std::endl;
	Bureaucrat c("c", 150);
	std::cout << c << std::endl;
	c.incrementGrade();
}

int main(void)
{
	testNameAndGradeConstructor("name and grade constructor");
	testCopyConstructor("copy constructor");
	testIncrementDecrement("increment and decrement");
	return (0);
}