/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:38:30 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 11:00:58 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl hrl = Harl();
	std::string level = "";
	do
	{
		std::cout<< "enter error level: ";
		getline(std::cin, level);
		if (std::cin.eof())
			break ;
		hrl.complain(level);
	} while (level.compare("exit"));
	
	return (0);
}