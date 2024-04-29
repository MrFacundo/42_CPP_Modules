/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 13:32:45 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cassert>


void printTitle(std::string testName)
{
	std::cout << "--------------------------------------------" << '\n';
	std::cout << "Test " << testName << '\n';
	std::cout << "--------------------------------------------" << '\n';
}


int main(void)
{
    int a = 2;
    int b = 3;
    ::swap<int>(a, b);
    printTitle("Type: int");
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "min(a, b) = " << ::min<int>(a, b) << '\n';
    std::cout << "max(a, b) = " << ::max<int>(a, b) << '\n';
    assert(a == 3);
    assert(b == 2);
    assert(::min<int>(a, b) == 2);
    assert(::max<int>(a, b) == 3);

    std::string c = "this is string nr 1";
    std::string d = "this is string nr 2";
    ::swap<std::string>(c, d);
    printTitle("Type: string");
    std::cout << "c = " << c << ", d = " << d << '\n';
    std::cout << "min(c, d) = " << ::min<std::string>(c, d) << '\n';
    std::cout << "max(c, d) = " << ::max<std::string>(c, d) << '\n';
    assert(c == "this is string nr 2");
    assert(d == "this is string nr 1");
    assert(::min<std::string>(c, d) == "this is string nr 1");

    Bureaucrat e("Bureaucrat 1", 1);
    Bureaucrat f("Bureaucrat 2", 2);
    ::swap<Bureaucrat>(e, f);
    printTitle("Type: Bureaucrat");
    std::cout << "e = " << e << "f = " << f << '\n';
    std::cout << "min(e, f) = " << ::min<Bureaucrat>(e, f) << '\n';
    std::cout << "max(e, f) = " << ::max<Bureaucrat>(e, f) << std::endl;
    assert(e.getName() == "Bureaucrat 2");
    assert(f.getName() == "Bureaucrat 1");
    assert(::min<Bureaucrat>(e, f).getName() == "Bureaucrat 1"); 
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}