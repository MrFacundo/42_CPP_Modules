/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:54 by facu              #+#    #+#             */
/*   Updated: 2024/05/06 20:17:10 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <list>
#include <vector>

#include "MutantStack.hpp"

void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing " << testName << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void testPushPop()
{
	MutantStack<int> mstack;

	// Test push
	mstack.push(5);
	mstack.push(17);
	assert(mstack.top() == 17);
	assert(mstack.size() == 2);

	// Test pop
	mstack.pop();
	assert(mstack.top() == 5);
	assert(mstack.size() == 1);

	// Test empty
	mstack.pop();
	assert(mstack.empty() == true);
	std::cout << "Test passed" << std::endl;
}

template <typename Container>
void testPushPop()
{
	MutantStack<int, Container> mstack;

	mstack.push(5);
	mstack.push(17);
	assert(mstack.top() == 17);
	assert(mstack.size() == 2);

	mstack.pop();
	assert(mstack.top() == 5);
	assert(mstack.size() == 1);

	mstack.pop();
	assert(mstack.empty() == true);
	std::cout << "Test passed" << std::endl;
}

template <typename Container>
void testIterator()
{
	MutantStack<int, Container> mstack;
	std::list<int> list;

	for (int i = 0; i < 10; ++i)
	{
		mstack.push(i);
		list.push_back(i);
	}

    typename MutantStack<int, Container>::iterator itStack = mstack.begin();
    typename MutantStack<int, Container>::iterator iteStack = mstack.end();

	std::list<int>::iterator itList = list.begin();
	std::list<int>::iterator iteList = list.end();

	while (itStack != iteStack && itList != iteList)
	{
		assert(*itStack == *itList);
		++itStack;
		++itList;
	}

	assert(itStack == iteStack && itList == iteList);
	std::cout << "Test passed" << std::endl;
}
int main()
{
	printTitle("push and pop default container int");
	testPushPop();
	printTitle("push and pop vector int");
	testPushPop<std::vector<int> >();
	printTitle("iterator deque container int");
	testIterator<std::deque<int> >();
	printTitle("iterator list container int");
	testIterator<std::list<int> >();
	return 0;
}