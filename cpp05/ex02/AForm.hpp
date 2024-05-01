/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:21:03 by facu              #+#    #+#             */
/*   Updated: 2024/04/14 19:21:17 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		AForm(void);
		std::string const name;
		bool is_signed;
		int const sign_grade;
		int const execute_grade;
	protected:
		virtual void executeImpl(const Bureaucrat &executor) const = 0;
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm(AForm const &src);
		virtual ~AForm(void);
		// OPERATORS
		AForm& operator=(AForm const &rhs);
		// GETTERS AND SETTERS
		std::string getName(void) const;
		int getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		// MEMBER FUNCTIONS
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const;
		// EXCEPTIONS
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

};

std::ostream &operator<<(std::ostream &out, AForm const &rhs);

#endif