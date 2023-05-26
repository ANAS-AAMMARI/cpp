/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:08:22 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/26 16:36:21 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	
	std::string type;

	// constrator
	public:
		Weapon(std::string type);
		~Weapon(void);
	// getters and setters
	public:
		const std::string& getType(void) const;
		void setType(const std::string type);
		
};

#endif