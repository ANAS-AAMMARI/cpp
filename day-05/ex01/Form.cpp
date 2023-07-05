/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:11:49 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/05 19:16:01 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), issigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : name(src.name), issigned(src.issigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form::~Form()
{
}

Form & Form::operator=(const Form & rhs)
{
	if (this != &rhs)
		this->issigned = rhs.issigned;
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->issigned);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->issigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form " << rhs.getName() << " is signed: " << rhs.getSigned() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (o);
}
