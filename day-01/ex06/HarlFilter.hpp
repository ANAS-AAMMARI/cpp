/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:35:53 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 12:39:34 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <iostream>

class HarlFilter
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		void complain( std::string level );
};

#endif