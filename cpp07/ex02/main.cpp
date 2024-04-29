/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:54 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 19:02:17 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
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


	std::cout << "char array: " << std::endl;
	Array<char> b(5);
	b.print();
	assert(b.size() == 5);
	assert(b[0] == 0);
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


int main(void)
{
	testSizeConstructor("size constructor");
	testCopyConstructor("copy constructor");
	testAssignmentOperator("assignment operator")
	return (0);
}
