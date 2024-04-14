/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/27 22:34:27 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void testNameAndGradeConstructor(void)
{
	printTitle("name and grade constructor");
	try
	{
		Bureaucrat a("a", 150);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("a", 151);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("a", 0);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testCopyConstructor(void)
{
	printTitle("copy constructor");
	Bureaucrat a("a", 4);
	Bureaucrat b(a);
	std::cout << b << std::endl;
}

void testIncrementDecrement(void)
{
	printTitle("increment and decrement");
	Bureaucrat a("a", 4);
	std::cout << a << std::endl;
	try
	{
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try
	{
		a.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	try
	{
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	Bureaucrat c("c", 150);
	std::cout << c << std::endl;
	try
	{
		c.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;
}

int main(void)
{
	testNameAndGradeConstructor();
	testCopyConstructor();
	testIncrementDecrement();
	return (0);
}