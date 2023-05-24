/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:27:07 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/24 18:28:46 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();

	// setter
	void setName(std::string name);
	void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif