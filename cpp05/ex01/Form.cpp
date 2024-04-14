/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:56:06 by facu              #+#    #+#             */
/*   Updated: 2024/04/14 18:29:55 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTORS AND DESTRUCTORS
Form::Form(void)
	: name("default_name"), is_signed(false), sign_grade(1), execute_grade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &src) : name(src.name), sign_grade(src.sign_grade), execute_grade(src.execute_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::Form(std::string const name, int sign_grade, int execute_grade)
	: name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	std::cout << "Form name, grade constructor called" << std::endl;
	if (sign_grade > max_grade || execute_grade > max_grade)
		throw(Form::GradeTooHighException());
	else if (sign_grade < min_grade || execute_grade < min_grade)
		throw(Form::GradeTooLowException());
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

// OPERATORS
Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
		is_signed = rhs.is_signed;
	return *this;
}

// GETTERS AND SETTERS
std::string Form::getName(void) const
{
	return name;
}

int Form::getSignGrade(void) const
{
	return sign_grade;
}

int Form::getExecuteGrade(void) const
{
	return execute_grade;
}

int Form::getIsSigned(void) const
{
	return is_signed;
}

std::ostream &operator<<(std::ostream &out, Form const &rhs)
{
	out <<  "Form name: "
		<<	rhs.getName()
		<< ", sign_grade: "
		<< rhs.getSignGrade()
		<< ", execute_grade: "
		<< rhs.getExecuteGrade()
		<< ", is_signed: "
		<< rhs.getIsSigned()
		<< std::endl;
	return out;
}

// MEMBER FUNCTIONS
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (is_signed)
	{
		std::cout << "Form is already signed" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}