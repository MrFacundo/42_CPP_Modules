/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 18:23:37 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
		Form a("a",150, 150);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST2" << std::endl;
	try {
		Form b("b",150, 151);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST3" << std::endl;
	try {
		Form c("c",150, 0);
		std::cout << c << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testCopyConstructor(std::string testName)
{
	printTitle(testName);
	Form a("a", 150, 150);
	Form b(a);
	std::cout << b << std::endl;
}

void testSignature(std::string testName)
{
	printTitle(testName);

	std::cout << "TEST1" << std::endl;
	Form a("a", 150, 150);
	Bureaucrat b("b", 150);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.signForm(a);
	std::cout << a << std::endl;

	std::cout << "TEST2" << std::endl;
	Form c("a", 1, 1);
	std::cout << c << std::endl;
	std::cout << b << std::endl;
	b.signForm(c);
	std::cout << c << std::endl;

	std::cout << "TEST3" << std::endl;
	std::cout << c << std::endl;
	Bureaucrat d("d", 75);
	d.signForm(c);
	std::cout << c << std::endl;
}

int main(void)
{
	testNameAndGradeConstructor("name and grade constructor");
	testCopyConstructor("copy constructor");
	testSignature("signature");
	return (0);
}