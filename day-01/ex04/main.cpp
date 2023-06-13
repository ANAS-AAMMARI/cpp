/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:41:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/13 18:11:43 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4 || !av[2][0] || !av[3][0])
	{
		std::cout << "Program arguments error" << std::endl;
		return (-1);
	}
	std::ifstream	in_f(av[1]);
	if (!in_f.is_open())
	{
		std::cout << "Could not open the input file " << av[1] << std::endl;
		return (-1);
	}
	std::string str = "";
	std::string av2(av[2]);
	std::string av3(av[3]);
	
	if(getline(in_f, str, '\0'))
	{
		size_t found = -1;
		while ((found = str.find(av2, found + 1)) != std::string::npos )
		{
			str.erase(found, av2.length());
			str.insert(found, av3);
		}
		in_f.close();

		std::string s(av[1]);
		std::string rp = s + ".replace";
		std::ofstream	out_f(rp);
		if (!out_f.is_open())
		{
			std::cout << "Could not open the output file" << rp << std::endl;
			return (-1);
		}
		out_f << str;
		out_f.close();
	}
	else
	{
		std::cout << "Could not read the input file" << std::endl;
		return (-1);
	}
	return (0);
}