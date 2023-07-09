/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:23 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/08 11:02:06 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat *b1;
	try
	{
		b1 = new Bureaucrat("b1", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << *b1 << std::endl;

	std::cout << std::endl;

	ShrubberyCreationForm sh = ShrubberyCreationForm("shrubberyCreationForm");
	RobotomyRequestForm rob = RobotomyRequestForm("robotomyRequestForm");
	PresidentialPardonForm pres = PresidentialPardonForm("presidentialPardonForm");

	// std::cout << sh << std::endl;
	// std::cout << rob << std::endl;
	// std::cout << pres << std::endl;
	try
	{
		// sh.beSigned(*b1);
		// rob.beSigned(*b1);
		pres.beSigned(*b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		// sh.execute(*b1);
		// rob.execute(*b1);
		pres.execute(*b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;

	std::cout << "--------signForm------------" << std::endl;
	b1->signForm(sh);
	b1->signForm(rob);
	b1->signForm(pres);

	std::cout << std::endl;

	std::cout << "---------executeForm--------" << std::endl;
	b1->executeForm(sh);
	b1->executeForm(rob);
	b1->executeForm(pres);
	std::cout << std::endl;
}
