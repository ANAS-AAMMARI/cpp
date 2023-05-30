/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:38:24 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 10:51:34 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "debug message !!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info message !!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning message !!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error message !!" << std::endl;	
}

void Harl::complain(std::string level)
{
	int i = -1;
	memberFuncPtr arrPtr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string arrStr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (++i < 4)
	{
		if (arrStr[i] == level)
		{
			(this->*arrPtr[i])();
			return ;
		}
	}
}
