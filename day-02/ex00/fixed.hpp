/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:00 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/05 15:13:40 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int	fixed;
	static const int number_fract;

	public:
		Fixed();
		Fixed(Fixed& fix);
		Fixed& operator=(const Fixed& fx);
		~Fixed();

	// getters & setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif