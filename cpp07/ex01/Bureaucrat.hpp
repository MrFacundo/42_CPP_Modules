/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:15:50 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 13:20:14 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

const int max_grade = 150;
const int min_grade = 1;

class Bureaucrat {

	private:
		std::string name;
		int grade;
	public:
		Bureaucrat(void);
		// CONSTRUCTORS AND DESTRUCTORS
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		// OPERATORS
		Bureaucrat& operator=(Bureaucrat const &rhs);
		bool operator <(Bureaucrat const &rhs) const;
		bool operator >(Bureaucrat const &rhs) const;
		// GETTERS AND SETTERS
		std::string getName(void) const;
		int getGrade(void) const;
		// MEMBER FUNCTIONS
		void incrementGrade(void);
		void decrementGrade(void);
		// EXCEPTIONS
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif