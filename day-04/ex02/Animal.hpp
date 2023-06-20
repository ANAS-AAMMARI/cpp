/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:40:41 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/19 18:07:46 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal & src);
		virtual ~Animal(void);
		Animal & operator=(const Animal & src);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif