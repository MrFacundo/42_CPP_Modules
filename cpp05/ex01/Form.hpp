/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:40:18 by facu              #+#    #+#             */
/*   Updated: 2024/02/27 23:38:53 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		Form(void);
		std::string const name;
		bool is_signed;
		int const sign_grade;
		int const execute_grade;
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Form(std::string name, int sign_grade, int execute_grade);
		Form(Form const &src);
		~Form(void);
		// OPERATORS
		Form& operator=(Form const &rhs);
		// GETTERS AND SETTERS
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		// MEMBER FUNCTIONS
		void beSigned(const Bureaucrat &bureaucrat);
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

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif