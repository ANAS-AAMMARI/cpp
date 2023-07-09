/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:07:42 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/08 11:43:22 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm Form;

class Intern
{
	public:
		Intern();
		Intern(const Intern & src);
		~Intern();
		Intern & operator=(const Intern & src);
		Form *makeForm(std::string formName, std::string targetForm);
};

#endif 