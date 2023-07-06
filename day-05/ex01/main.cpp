/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:23 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/06 14:22:06 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat b1 = Bureaucrat("Bureaucrat1", 10);
	Bureaucrat b2 = Bureaucrat("Bureaucrat3", 75);
	
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << std::endl;

	Form f1 = Form("Form1", 1, 1);
	Form f2 = Form("Form2", 150, 150);
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << std::endl;

	std::cout << "----- EXCEPTIONS ----" << std::endl;
	std::cout << std::endl;

	try
	{
		Form("Form3", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form("Form4", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form frm = Form("Form5", 70, 10);
		frm.beSigned(b1);
		b1.signForm(frm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}