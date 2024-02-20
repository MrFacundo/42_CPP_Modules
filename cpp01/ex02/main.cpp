/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2023/12/26 16:20:28 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}