/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:22:46 by facu              #+#    #+#             */
/*   Updated: 2024/05/06 19:09:24 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(MutantStack const & src) : std::stack<T, Container>(src) {}
		virtual ~MutantStack() {}

		MutantStack & operator=(MutantStack const & rhs) {
			if (this != &rhs) {
				std::stack<T, Container>::operator=(rhs);
			}
			return *this;
		}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		iterator begin() {
			return std::stack<T, Container>::c.begin();
		}

		iterator end() {
			return std::stack<T, Container>::c.end();
		}
};

#endif