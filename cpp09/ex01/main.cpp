/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:14:32 by facu              #+#    #+#             */
/*   Updated: 2024/05/04 21:17:13 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void testSpansShort()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(0);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(sp.shortestSpan() == 2);
    assert(sp.longestSpan() == 17);
}



void testSpansLarge()
{
    Span sp = Span(10000);

    std::srand(std::time(0));

    try
    {
        for (int i = 0; i < 10000; i++)
            sp.addNumber(std::rand() % 10000);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testSpansRange()
{
    Span sp = Span(10000);

    std::vector<int> numbers(10000);
    for (int i = 0; i < 10000; i++)
        numbers[i] = i;
    try
    {
        sp.addNumber(numbers.begin(), numbers.end());
        assert(sp.shortestSpan() == 1);
        assert(sp.longestSpan() == 9999);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testFullContainer()
{
    Span sp = Span(3);

    try
    {
        sp.addNumber(0);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
}

void testSpanWithNoElements()
{
    Span sp3 = Span(0);
    try
    {
       std::cout << sp3.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
}

int main()
{
    printTitle("Test spans short int");
    testSpansShort();

    printTitle("Test spans large int");
    testSpansLarge();

    printTitle("Test spans range");
    testSpansRange();

    printTitle("Test AddNumber full container");
    testFullContainer();

    printTitle("Test Span with no elements");
    testSpanWithNoElements();

    return 0;
}