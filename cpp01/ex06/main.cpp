/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:38:54 by facu              #+#    #+#             */
/*   Updated: 2024/01/05 15:51:14 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 2)
	{
		harl.complain(av[1]);
		return (0);
	}
	else
	{
		std::cout << "Usage: ./harlFilter <complaint level>" << std::endl;
		return (1);
	}
}