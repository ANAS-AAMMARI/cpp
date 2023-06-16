/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:00:11 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/16 15:26:33 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string& Name): Name(Name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << Name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct)
{
	*this = ct;
	std::cout << "ClapTrap " << Name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " is destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->Name = other.Name;
	this->HitPoint = other.HitPoint;
	this->EnergyPoint = other.EnergyPoint;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << Name << " attack " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoint -= amount;
	if (this->HitPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is dead" << std::endl;
		this->HitPoint = 0;
		return ;
	}
	std::cout << "ClapTrap " << Name << " is damaged for " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is out of energy" << std::endl;
		return ;
	}
	this->HitPoint += amount;
	this->EnergyPoint --;
	std::cout << "ClapTrap " << Name << " is repaired for " << amount << " points of damage!" << std::endl;
}
