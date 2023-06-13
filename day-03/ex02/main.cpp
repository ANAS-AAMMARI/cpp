/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:11:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/12 15:29:42 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clap");
	FragTrap frag("Frag");
	ScavTrap scav("Scav");

	frag.attack("Scav");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	frag.highFivesGuys();
	return (0);
}
