/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:04 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 13:34:19 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "error argument !!\n";
		return (-1);
	}
	else
	{
		HarlFilter fltr = HarlFilter();
		fltr.complain(av[1]);
	}
	return (0);
}
