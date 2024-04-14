/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/14 18:30:31 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
		Form a("a", 150, 150);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form a("a", 151, 151);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form a("a", 0, 0);
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
	Form a("a", 150, 150);
	Form b(a);
	std::cout << b << std::endl;
}

void testSignature(void)
{
	printTitle("increment and decrement");
	Form a("a", 150, 150);
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

	Form b("b", 150, 150);
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

	Form c("c", 150, 150);
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
	testSignature();
	return (0);
}