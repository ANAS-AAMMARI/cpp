/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:23 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/08 16:42:33 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();
	
	public:
	static void convert(const std::string &intput);
};

#endif