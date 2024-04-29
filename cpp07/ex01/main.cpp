/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:14:32 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 16:36:55 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cassert>

void addOne(int &n)
{
	n++;
}

void	toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void    promote(Bureaucrat &b)
{
    b.incrementGrade();
}

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << '\n';
	std::cout << "Test " << testName << '\n';
	std::cout << "--------------------------------------------" << '\n';
}

int main(void)
{
    printTitle("Array type: int");
    int intArray[] = {1, 2, 3, 4, 5};
    iter<int>(intArray, 5, addOne);
    iter<int>(intArray, 5, print<int>);
    assert(intArray[0] == 2);

    printTitle("Array type: char");
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    iter<char>(charArray, 5, toUpper);
    iter<char>(charArray, 5, print<char>);
    assert(charArray[0] == 'A');

    printTitle("Array type: bureaucrat");
    Bureaucrat bureaucratArray[] = {Bureaucrat("John", 1), Bureaucrat("Jane", 150)};
    iter<Bureaucrat>(bureaucratArray, 2, promote);
    iter<Bureaucrat>(bureaucratArray, 2, print<Bureaucrat>);
    assert(bureaucratArray[0].getGrade() == 2);
    return 0;
}