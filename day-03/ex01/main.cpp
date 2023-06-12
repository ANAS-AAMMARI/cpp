/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:56:40 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/12 14:03:43 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("_ScavTrap");

	scav.attack("target");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate();
	return (0);
}