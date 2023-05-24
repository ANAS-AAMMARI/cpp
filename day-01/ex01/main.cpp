/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:34 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/24 18:40:01 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zmb = zombieHorde(4, "bo3bo3");
	zmb[0].announce();
	zmb[1].announce();
	zmb[2].announce();
	zmb[3].announce();

	delete[] zmb;
	return (0);
}