/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:54 by facu              #+#    #+#             */
/*   Updated: 2024/04/24 17:45:10 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <math.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	std::cout << "Identify from pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identify from reference: ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}