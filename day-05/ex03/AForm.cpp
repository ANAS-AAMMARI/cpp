/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:11:49 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/06 13:15:02 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), issigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : name(src.name), issigned(src.issigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->issigned = rhs.issigned;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSigned() const
{
	return (this->issigned);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->issigned = true;
		std::cout << "signed" << std::endl;
	}	
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << "Form " << rhs.getName() << " is signed: " << rhs.getSigned() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (o);
}
