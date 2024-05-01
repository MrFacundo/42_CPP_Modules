/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:54 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 20:15:33 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Bureaucrat.hpp"
#include <cassert>


void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void testSizeConstructor(std::string testName)
{
	printTitle(testName);
	std::cout << "int array: " << std::endl;
	Array<int> a(5);
	a.print();
	assert(a.size() == 5);
	assert(a[0] == 0);
	try
	{
		std::cout << a[6] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<  std::endl;
	}
	std::cout << "char array: " << std::endl;
	Array<char> b(5);
	b.print();
	assert(b.size() == 5);
	assert(a[0] == 0);
	Array<Bureaucrat> c(5);
	c[0] = Bureaucrat("ftroiter", 1);
	assert(c[0].getName() == "ftroiter");
	c.print();
}

void testCopyConstructor(std::string testName)
{
	printTitle(testName);
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	Array<int> b(a);
	std::cout << "a array: " << std::endl;
	a.print();
	std::cout << "b array: " << std::endl;
	b.print();
	assert(a.size() == b.size());
	assert(a[0] == b[0]);
	assert(a[1] == b[1]);
	assert(a[2] == b[2]);
}

void testAssignmentOperator(std::string testName)
{
	printTitle(testName);
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	Array<int> b(2);
	b[0] = 4;
	b[1] = 5;
	b = a;
	std::cout << "a array: " << std::endl;
	a.print();
	std::cout << "b array: " << std::endl;
	b.print();
	assert(a.size() == b.size());
	assert(a[0] == b[0]);
	assert(a[1] == b[1]);
	assert(a[2] == b[2]);
}

void	testSizeFunction(std::string testName)
{
	printTitle(testName);
	Array<int> a;
	assert(a.size() == 0);
	Array<int> b(3);
	assert(b.size() == 3);
	Array<int> c(5);
	assert(c.size() == 5);
	std::cout << "tests passed" << std::endl;
}


int main(void)
{
	testSizeConstructor("size constructor");
	testCopyConstructor("copy constructor");
	testAssignmentOperator("assignment operator");
	testSizeFunction("size function");
	std::cout << "All tests passed" << std::endl;
	return 0;
}
