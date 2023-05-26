/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:45:49 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/26 15:56:21 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp): weapon(wp)
{
	this->name = name;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType()
	<< std::endl;	
}
