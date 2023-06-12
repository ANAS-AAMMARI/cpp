/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:14:39 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/11 16:28:59 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::number_fract = 8;

Fixed::Fixed(const int i)
{
	this->fixed = i << this->number_fract;
}

Fixed::Fixed(const float f)
{
	this->fixed = roundf(f * (1 << this->number_fract));
}

Fixed::Fixed(void):fixed(0)
{
}

Fixed::Fixed(const Fixed &fix)
{
	// (*this).setRawBits(fix.getRawBits());
	(*this) = fix;
}


Fixed& Fixed::operator=(const Fixed& fx)
{
	if (this != &fx)
	{
		this->fixed = fx.fixed;
	}
	return (*this);
}

Fixed::~Fixed()
{
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

// bool operators
bool Fixed::operator>(const Fixed& fx) const
{
	return (this->fixed > fx.fixed);
}

bool Fixed::operator<(const Fixed& fx) const
{
	return (this->fixed < fx.fixed);
}

bool Fixed::operator>=(const Fixed& fx) const
{
	return (this->fixed >= fx.fixed);
}

bool Fixed::operator<=(const Fixed& fx) const
{
	return (this->fixed <= fx.fixed);
}

bool Fixed::operator==(const Fixed& fx) const
{
	return (this->fixed == fx.fixed);
}

bool Fixed::operator!=(const Fixed& fx) const
{
	return (this->fixed != fx.fixed);
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& fx) const
{
	return (Fixed(this->toFloat() + fx.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fx) const
{
	return (Fixed(this->toFloat() - fx.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fx) const
{
	return (Fixed(this->toFloat() * fx.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fx) const
{
	return (Fixed(this->toFloat() / fx.toFloat()));
}

// increment/decrement operators

Fixed& Fixed::operator++(void)
{
	++this->fixed;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed fx = *this;
	this->operator++();
	return (fx);
}

Fixed& Fixed::operator--(void)
{
	--this->fixed;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed fx = *this;
	this->operator--();
	return (fx);
}

// min/max functions

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
