/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:57:52 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/11 13:08:35 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed;

std::ostream & operator<<( std::ostream & os, Fixed const & fx);

class Fixed
{
	int	fixed;
	static const int number_fract;

	public:
		//constructors & destructor
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		
		// operators overload assignation
		Fixed& operator=(const Fixed& fx);
		
		// operators overload bool
		bool operator>(const Fixed& fx) const;
		bool operator<(const Fixed& fx) const;
		bool operator>=(const Fixed& fx) const;
		bool operator<=(const Fixed& fx) const;
		bool operator==(const Fixed& fx) const;
		bool operator!=(const Fixed& fx) const;
		
		// operators overload arithmetics
		Fixed operator+(const Fixed& fx) const;
		Fixed operator-(const Fixed& fx) const;
		Fixed operator*(const Fixed& fx) const;
		Fixed operator/(const Fixed& fx) const;
		
		// operators overload increment/decrement
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		
		// min max static functions
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		// getters & setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
		// convert
		float toFloat( void ) const;
		int toInt( void ) const;

};


#endif