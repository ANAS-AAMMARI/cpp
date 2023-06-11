/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:56:19 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/11 10:47:26 by aaammari         ###   ########.fr       */
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
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed(const int i);
		Fixed(const float f);
		Fixed& operator=(const Fixed& fx);
		~Fixed();

	// getters & setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	// convert
		float toFloat( void ) const;
		int toInt( void ) const;

};

// std::ostream & operator<<( std::ostream & os, Fixed const & fx);

#endif