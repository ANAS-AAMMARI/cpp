/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:59:38 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/11 17:03:29 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("ClapTrap");
	ClapTrap ct2(ct);
	ClapTrap ct3;
	ct3 = ct2;
	ct.attack("target");
	ct.takeDamage(5);
	ct.beRepaired(5);
	return (0);
}