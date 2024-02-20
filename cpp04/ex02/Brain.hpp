/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:50:26 by facu              #+#    #+#             */
/*   Updated: 2024/02/19 18:17:19 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <fstream>

#define IdeasSize 100

class Brain
{
	private:
		std::string ideas[IdeasSize];
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);
		Brain &operator=(const Brain &rhs);
		void printIdeas(void) const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif