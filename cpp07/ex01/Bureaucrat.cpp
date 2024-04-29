/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:07:28 by facu              #+#    #+#             */
/*   Updated: 2024/04/29 13:16:29 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name) , grade(src.grade)
{
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	if (grade > max_grade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade < min_grade)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat(void)
{
}

// OPERATORS
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		grade = rhs.grade;
	}
	return *this;
}

// GETTERS AND SETTERS
std::string Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (grade >= max_grade)
			throw(Bureaucrat::GradeTooHighException());
		grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (grade <= min_grade)
			throw(Bureaucrat::GradeTooLowException());
		grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << "Bureaucrat name: "
		<< rhs.getName()
		<< ", bureaucrat grade: "
		<< rhs.getGrade()
		<< std::endl;
	return out;
}

bool Bureaucrat::operator<(Bureaucrat const &rhs) const
{
	return grade < rhs.grade;
}

bool Bureaucrat::operator>(Bureaucrat const &rhs) const
{
	return grade > rhs.grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Can not set grade. Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Can not set grade. Grade too low";
}