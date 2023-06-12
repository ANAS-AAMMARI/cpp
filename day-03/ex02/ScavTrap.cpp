/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:18:24 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/12 14:03:29 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors and destructors

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// Operators overload

ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->Name = other.Name;
	this->HitPoint = other.HitPoint;
	this->EnergyPoint = other.EnergyPoint;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

// Member functions

void ScavTrap::attack(std::string const & target)
{
	if (this->HitPoint < 1 || this->EnergyPoint < 1)
	{
		std::cout << "ScavTrap " << this->Name << " can't attack because he's dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void ScavTrap::guardGate(void)
{
	if (this->HitPoint < 1 || this->EnergyPoint < 1)
	{
		std::cout << "ScavTrap " << this->Name << " can't enter in Gate keeper mode because he's dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " has entered in Gate keeper mode" << std::endl;
}
