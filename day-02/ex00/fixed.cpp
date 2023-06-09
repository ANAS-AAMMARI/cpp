/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:27:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/09 18:42:02 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::number_fract = 8;

Fixed::Fixed():fixed(0)
{
	std::cout << "Default constructor called" << std:: endl;
}

Fixed::Fixed(Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this).setRawBits(fix.getRawBits());
	// (*this) = fix;
}

Fixed& Fixed::operator=(const Fixed& fx)
{
	if (this != &fx)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->fixed = fx.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}