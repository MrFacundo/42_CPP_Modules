/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/04/23 16:43:01 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	ScalarConverter::convert(argv[1]);
    // ScalarConverter test = ScalarConverter(); // class should not be instantiable
    /*  
    Char: !
    Int: 42
    Int: 44142
    Float: 3.14
    Double: -4.2
    Double: 1.
    */
	return (0);
}
