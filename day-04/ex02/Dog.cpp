/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:40:54 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/19 17:15:09 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog & src)
{
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog & src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		this->brain = new Brain();
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Wouf wouf" << std::endl;
}

//getters and setters

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}

