/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:43 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 17:58:21 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void cmd(PhoneBook ph)
{
	std::string cmd = "";
	do{
		if (std::cin.eof())
			return ;
		std::cout <<std::internal << std::setw(28) << " -------------help----------------" << std::endl;
		std::cout <<std::left << std::setw(28) << "|	1- \"ADD\" Contact" << std::right << "|" << std::endl;
		std::cout <<std::left << std::setw(28) << "|	2- \"SEARCH\" for a Contact" << std::right << "|" << std::endl;
		std::cout <<std::left << std::setw(28) << "|	3- \"EXIT\"" << std::right << "|" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
				ph.ADD();
		else if (cmd.compare("SEARCH") == 0)
			ph.SEARCH();
	}while (cmd.compare("EXIT"));
	
}

int main(void)
{
	PhoneBook ph = PhoneBook();
	cmd(ph);
	return (0);
}