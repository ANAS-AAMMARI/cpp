/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:50:34 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/06 18:28:13 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
		void execute(Bureaucrat const & executor) const;
};

#endif