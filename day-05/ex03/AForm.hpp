/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:04:06 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/06 15:02:45 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	name;
		bool				issigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm();
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		AForm(const AForm & src);
		virtual ~AForm();
		AForm & operator=(const AForm & rhs);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif