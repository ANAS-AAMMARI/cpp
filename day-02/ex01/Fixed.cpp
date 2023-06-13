/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:04:55 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/12 18:59:38 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::number_fract = 8;

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed = i << this->number_fract;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(f * (1 << this->number_fract));
}

Fixed::Fixed(void):fixed(0)
{
	std::cout << "Default constructor called" << std:: endl;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	// (*this).setRawBits(fix.getRawBits());
	(*this) = fix;
}


Fixed& Fixed::operator=(const Fixed& fx)
{
	if (this != &fx)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->fixed = fx.fixed;
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

float Fixed::toFloat(void) const
{
	return (this->fixed / (float)(1 << this->number_fract));
}

int Fixed::toInt(void) const
{
	return (this->fixed >> this->number_fract);
}

std::ostream & operator<<( std::ostream & os, Fixed const & fx ) {
    os << fx.toFloat();
    return os;
}