/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:29:37 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/09 17:58:53 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	return (false);
}

bool checkInt(std::string input)
{
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool checkFloat(std::string input)
{
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] && input[i] != '.')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (input[i] == '.')
		i++;
	while (input[i] && input[i] != 'f')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (input[i] == 'f')
		i++;
	if (input[i])
		return (false);
	return (true);
}

bool checkDouble(std::string input)
{
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] && input[i] != '.')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (input[i] == '.')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool checkPseudo(std::string input)
{
	std::string pseudo[5] = {"nan", "nanf", "+inf", "-inf", "inff"};
	for (int i = 0; i < 5; i++)
	{
		if (input == pseudo[i])
			return (true);
	}
	return (false);
}
int findType(std::string input)
{
	if (checkChar(input))
		return (1);
	if (checkInt(input))
		return (2);
	if (checkFloat(input))
		return (3);
	if (checkDouble(input))
		return (4);
	if (checkPseudo(input))
		return (5);
	return (0);
}

void handleChar(char inp)
{
	bool isChar = true;
	if (inp < 32 || inp > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		isChar = false;
	}
	if (inp < 0 || inp > 127)
	{
		std::cout << "char: impossible" << std::endl;
		isChar = false;
	}

	if (isChar)
		std::cout << "char: " << inp << std::endl;
	std::cout << "int: " << static_cast<int>(inp) << std::endl;
	std::cout << "float: " << static_cast<float>(inp) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(inp) << ".0" << std::endl;
}

void handleInt(long int inp)
{
	bool isInt = true;
	if (inp < INT_MIN || inp > INT_MAX)
		isInt = false;
	if (inp < 0 || inp > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((inp < 32 || inp > 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(inp) << std::endl;
	if (isInt)
		std::cout << "int: " << static_cast<int>(inp) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (inp < 1000000 && inp > -1000000)
		std::cout << "float: " << static_cast<float>(inp) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(inp) << "f" << std::endl;
	if (inp < 1000000 && inp > -1000000)
		std::cout << "double: " << static_cast<double>(inp) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(inp) << std::endl;
}

void handleFloat(float inp)
{
	if (inp < 0 || inp > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((inp < 32 || inp > 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(inp) << std::endl;
	if (inp < INT_MIN || inp > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(inp) << std::endl;
	if (inp < std::numeric_limits<float>::min() || inp > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else if (inp < 1000000)
	{
		std::cout << "float: " << static_cast<float>(inp) << ".0f" << std::endl;
	}	
	else
		std::cout << "float: " << static_cast<float>(inp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(inp) << ".0" << std::endl;
}

void handleDouble(double inp)
{
	if (inp < 0 || inp > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((inp < 32 || inp > 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(inp) << std::endl;
	if (inp < INT_MIN || inp > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(inp) << std::endl;
	if (inp == static_cast<int>(inp))
		std::cout << "float: " << static_cast<float>(inp) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(inp) << "f" << std::endl;
	std::cout << "float: " << static_cast<float>(inp) << "f" << std::endl;
	if (inp < std::numeric_limits<double>::min() || inp > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else if (inp < 1000000 && inp > -1000000)
		std::cout << "double: " << inp << ".0" << std::endl;
	else
		std::cout << "double: " << inp << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	if (findType(input) == 1)
	{
		char d = input[0];
		handleChar(d);
	}
	else if (findType(input) == 2)
	{
		long int i = std::strtoll(input.c_str(), NULL, 10);
		handleInt(i);
	}	
	else if (findType(input) == 3)
	{
		float f = std::stof(input);
		handleFloat(f);
	}	
	else if (findType(input) == 4)
	{
		double d = static_cast<double>(atof(input.c_str()));
		handleDouble(d);
	}
	else if (findType(input) == 5)
	{
		float d = static_cast<float>(atof(input.c_str()));
		if (input == "nan" || input == "nanf")
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
	else
		std::cout << "Error: Invalid input" << std::endl;
}
