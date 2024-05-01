/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:46:27 by facu              #+#    #+#             */
/*   Updated: 2024/04/14 22:46:27 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

// CONSTRUCTORS AND DESTRUCTORS
AForm::AForm(void)
	: name("default_name"), is_signed(false), sign_grade(1), execute_grade(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : name(src.name), sign_grade(src.sign_grade), execute_grade(src.execute_grade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::AForm(std::string const name, int sign_grade, int execute_grade)
	: name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	std::cout << "Form name, grade constructor called" << std::endl;
		if (sign_grade < max_grade || execute_grade < max_grade)
			throw(AForm::GradeTooHighException());
		else if (sign_grade > min_grade || execute_grade > min_grade)
			throw(AForm::GradeTooLowException());
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

// OPERATORS
AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &rhs)
		is_signed = rhs.is_signed;
	return *this;
}

// GETTERS AND SETTERS
std::string AForm::getName(void) const
{
	return name;
}

int AForm::getSignGrade(void) const
{
	return sign_grade;
}

int AForm::getExecuteGrade(void) const
{
	return execute_grade;
}

int AForm::getIsSigned(void) const
{
	return is_signed;
}


// OPERATOR OVERLOADS

std::ostream &operator<<(std::ostream &out, AForm const &rhs)
{
	out <<  "AForm name: "
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
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (is_signed)
	{
		std::cout << "AForm is already signed" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!is_signed)
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > execute_grade)
		throw(AForm::GradeTooLowException());
	this->executeImpl(executor);
}

// EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed bro";
}