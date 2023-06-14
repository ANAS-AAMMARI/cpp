/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:55:57 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/14 10:58:32 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// constructors and destructor
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap & src);
		~FragTrap(void);

		// operator = overloads
		FragTrap & operator=(const FragTrap & other);
	
		// member functions
		void highFivesGuys(void);
		void attack(std::string const & target);
};

#endif