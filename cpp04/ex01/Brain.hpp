/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:50:26 by facu              #+#    #+#             */
/*   Updated: 2024/02/19 00:38:52 by facu             ###   ########.fr       */
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