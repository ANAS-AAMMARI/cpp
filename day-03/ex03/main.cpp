/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:11:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/14 13:32:56 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	*DiamondTrap1 = new DiamondTrap("DiamondTrap1");
	DiamondTrap	*DiamondTrap2 = new DiamondTrap("DiamondTrap2");
	DiamondTrap1->attack("DiamondTrap2");
	DiamondTrap2->attack("DiamondTrap1");
	DiamondTrap1->whoAmI();
	DiamondTrap2->whoAmI();
	delete DiamondTrap1;
	delete DiamondTrap2;
	return (0);
}
