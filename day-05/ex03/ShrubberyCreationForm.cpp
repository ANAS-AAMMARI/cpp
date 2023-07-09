/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:11:16 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/07 17:12:26 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	this->target = src.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "ShrubberyCreationForm is executed" << std::endl;
	std::ofstream out(this->target + "_shrubbery");
	if (out.is_open())
	{
		out << "     ccee88oo" << std::endl;
		out << "  C8O8O8Q8PoOb o8oo" << std::endl;
		out << " dOB69QO8PdUOpugoO9bD" << std::endl;
		out << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
		out << "    6OuU  /p u gcoUodpP" << std::endl;
		out << "      \\\\\\//  /douUP" << std::endl;
		out << "        \\\\\\////" << std::endl;
		out << "         |||/\\" << std::endl;
		out << "         |||\\/" << std::endl;
		out << "         |||||||" << std::endl;
		out << "         |||||||" << std::endl;
		out << "   .....//||||\\...." << std::endl;
		out.close();
	}
	else
		std::cout << "Could not open the file" << std::endl;
}