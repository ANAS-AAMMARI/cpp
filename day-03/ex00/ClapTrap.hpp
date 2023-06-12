/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:00:34 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/11 17:13:15 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	std::string Name;
	unsigned int HitPoint;
	unsigned int EnergyPoint;
	unsigned int AttackDamage;

	public:
		// constructor & destructor
		ClapTrap();
		ClapTrap(const std::string& Name);
		ClapTrap(const ClapTrap& ct);
		~ClapTrap();
	
		// operator overloading = 
		ClapTrap& operator=(const ClapTrap& other);

		// object behavers
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
};

#endif