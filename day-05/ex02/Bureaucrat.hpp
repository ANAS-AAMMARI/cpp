/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:37:57 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/07 17:43:57 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	typedef AForm Form;

private:
	std::string const name;
	int grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::string const getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(const Form &form) const;
	void executeForm(const Form &form) const;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif