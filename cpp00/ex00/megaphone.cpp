/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:13:44 by facu              #+#    #+#             */
/*   Updated: 2023/12/14 12:27:05 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
			{
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
