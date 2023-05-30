/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:37 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 12:59:50 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void HarlFilter::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "debug message !!\n" << std::endl;
}

void HarlFilter::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "info message !!\n" << std::endl;
}

void HarlFilter::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "warning message !!\n" << std::endl;
}

void HarlFilter::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "error message !!" << std::endl;	
}

void HarlFilter::complain(std::string level)
{
	int i = -1;
	std::string arrStr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (++i < 4)
	{
		if (arrStr[i] == level)
			break ;
	}
	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	
	
}