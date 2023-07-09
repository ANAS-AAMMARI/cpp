/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:15:38 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/08 11:40:50 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(const Intern & src)
{
	(void)src;
	return (*this);
}

Form *Intern::makeForm(std::string formName, std::string targetForm)
{
	std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form *formPtr[] = {new RobotomyRequestForm(targetForm), new PresidentialPardonForm(targetForm), new ShrubberyCreationForm(targetForm)};
	int i = -1;
	while (++i < 3)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formPtr[i]);
		}
	}
	std::cerr << "Intern cannot create " << formName << " form" << std::endl;
	return (nullptr);
}

