/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:15:50 by facu              #+#    #+#             */
/*   Updated: 2024/05/01 15:45:10 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

const int max_grade = 1;
const int min_grade = 150;

class AForm;
class Bureaucrat {

	private:
		Bureaucrat(void);
		std::string const name;
		int grade;
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		// OPERATORS
		Bureaucrat& operator=(Bureaucrat const &rhs);
		// GETTERS AND SETTERS
		std::string getName(void) const;
		int getGrade(void) const;
		// MEMBER FUNCTIONS
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &form);
		void executeForm(AForm const &form) const;
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