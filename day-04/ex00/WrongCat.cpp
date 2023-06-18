/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a WrongCat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:05:50 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/16 16:23:28 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & src)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat makes a sound" << std::endl;
}

