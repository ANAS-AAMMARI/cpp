/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:46:51 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 21:06:02 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat & src)
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat & src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		this->brain = new Brain(*src.getBrain());
	}	
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}

//getters and setters

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}

void Cat::setBrain(Brain *brain)
{
	this->brain = brain;
}
