/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:47:00 by facu              #+#    #+#             */
/*   Updated: 2024/05/20 17:33:53 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &str) : str(str)
{
	calculate();
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN()
{
}

void RPN::display()
{
	std::cout << result << std::endl;
}
void RPN::calculate()
{
	std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operation.size() < 2)
			{
				throw std::runtime_error("Not enough values");
			}
			int a = operation.top();
			operation.pop();
			int b = operation.top();
			operation.pop();
			if (token == "+")
			{
				operation.push(b + a);
			}
			else if (token == "-")
			{
				operation.push(b - a);
			}
			else if (token == "*")
			{
				operation.push(b * a);
			}
			else if (token == "/")
			{
				operation.push(b / a);
			}
		}
		else
		{
			std::stringstream ss(token);
			int num;
			if (!(ss >> num))
				throw std::runtime_error("Error");
			ss >> num;
			operation.push(num);
		}
	}
	if (operation.size() != 1)
	{
		throw std::runtime_error("Too many values");
	}
	result = operation.top();
}