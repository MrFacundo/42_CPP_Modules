/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:14:32 by facu              #+#    #+#             */
/*   Updated: 2024/04/23 18:36:22 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <cassert>
#include <iostream>
#include <cassert>

int main(void)
{
	// Test 1: Basic functionality
	Data data;
	data.id = 42;
	data.pid = 21;
	data.s1 = "What is this even for?";

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Test 1: " << ptr->id << ", " << ptr->pid << ", " << ptr->s1 << std::endl;
	assert(ptr->id == 42);
	assert(ptr->pid == 21);
	assert(ptr->s1 == "What is this even for?");

	// Test 2: Different data
	Data data2;
	data2.id = 123;
	data2.pid = 456;
	data2.s1 = "Another test";

	raw = Serializer::serialize(&data2);
	ptr = Serializer::deserialize(raw);

	std::cout << "Test 2: " << ptr->id << ", " << ptr->pid << ", " << ptr->s1 << std::endl;
	assert(ptr->id == 123);
	assert(ptr->pid == 456);
	assert(ptr->s1 == "Another test");

	// Test 3: Empty string
	Data data3;
	data3.id = 789;
	data3.pid = 0;
	data3.s1 = "";

	raw = Serializer::serialize(&data3);
	ptr = Serializer::deserialize(raw);

	std::cout << "Test 3: " << ptr->id << ", " << ptr->pid << ", " << ptr->s1 << std::endl;
	assert(ptr->id == 789);
	assert(ptr->pid == 0);
	assert(ptr->s1 == "");

	std::cout << "All tests passed!" << std::endl;

	return 0;
}