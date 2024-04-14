/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:07:28 by facu              #+#    #+#             */
/*   Updated: 2024/02/27 22:33:49 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	std::cout << "Bureaucrat name, grade constructor called" << std::endl;
	if (grade > max_grade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade < min_grade)
		throw(Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// OPERATORS
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &rhs)
	{
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
	if (grade > max_grade)
		throw(Bureaucrat::GradeTooHighException());
	grade++;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade < min_grade)
		throw(Bureaucrat::GradeTooLowException());
	grade--;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade: " << rhs.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Can not set grade. Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Can not set grade. Grade too low";
}