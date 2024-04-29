/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:36:37 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 16:27:12 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t const length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	print(T &t)
{
	std::cout << t << std::endl;
}
#endif