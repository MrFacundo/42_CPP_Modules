/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:15:50 by facu              #+#    #+#             */
/*   Updated: 2024/02/20 21:20:29 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:
		Bureaucrat(void);
		std::string const name;
		int grade;
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		// OPERATORS
		Bureaucrat & operator=(Bureaucrat const & rhs);
		// GETTERS AND SETTERS
		std::string getName(void) const;
		int getGrade(void) const;
		// MEMBER FUNCTIONS
		void incrementGrade(void);
		void decrementGrade(void);
		// EXCEPTIONS
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif