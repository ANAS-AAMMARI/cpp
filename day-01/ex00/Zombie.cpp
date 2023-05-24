/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:35:50 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/24 16:37:00 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


// members functions
Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << "object has been distroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;	
}

// non-members functions

Zombie* newZombie( std::string name )
{
	Zombie *zmb = new Zombie();
	zmb->setName(name);
	return (zmb);
}

void randomChump( std::string name )
{
	Zombie zmb = Zombie();
	zmb.setName(name);
	zmb.announce();
}