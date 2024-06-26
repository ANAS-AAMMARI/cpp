/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:50 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/30 18:21:49 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::objectCount = 0;

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

int	check_space(std::string s)
{
	size_t i = 0;
	const char *str = s.c_str();
	while (str[i] && std::isspace(str[i]))
		i++;
	return (i == s.length());
}

void PhoneBook::ADD(void)
{
	std::string firstName = "";
	std::string lastName = "";
	std::string nickname = "";
	std::string phoneNumber = "";
	std::string darkestSecret = "";
	int idx = objectCount;

	do
	{	
		std::cout << "enter ur First Name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return ;
	}while(firstName.empty() || check_space(firstName));
	
	do
	{
		std::cout << "enter ur lastName: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return ;
	}while(lastName.empty() || check_space(lastName));
	
	do
	{
		std::cout << "enter ur nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ;
	}while(nickname.empty() || check_space(nickname));
	
	do
	{
		std::cout << "enter ur phoneNumber: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return ;
	}while(phoneNumber.empty() || check_space(phoneNumber));
	
	do
	{
		std::cout << "enter ur darkestSecret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return ;		
	}while(darkestSecret.empty() || check_space(darkestSecret));
	
	Contact cnt = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (idx >= 8)
	{
		std::cout << idx << "\n";
		this->contacts[idx % 8] = cnt;
		objectCount++;
	}	
	else if (idx >= 0 && idx < 8)
	{
		this->contacts[idx] = cnt;
		objectCount++;
	}	
}

std::string _format(std::string value)
{
	std::string val = value;
	if (val.length() > 10)
		val = val.substr(0, 9) + ".";
	return (val);
}

int	check_digit(std::string str)
{
	if (str.empty())
		return (0);
	size_t i = 0;
	while (str[i] && std::isdigit(str[i]))
		i++;
	return (i == str.length());
}

void table_header()
{
	std::cout << " " << std::right << std::setw(10) << "-------------------------------------------" << "\n";
	std::cout << "|" << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << _format("FirstName") << "|";
	std::cout << std::right << std::setw(10) << _format("LastName") << "|";
	std::cout << std::right << std::setw(10) << _format("NickName") << "|" << std::endl;
	std::cout << " " << std::right << std::setw(10) << "-------------------------------------------" << "\n";
}

void PhoneBook::SEARCH(void)
{
	std::string str;
	int idx;
	if (objectCount == 0)
	{
		std::cout << "your PhoneBook is empty try to ADD contact" << std::endl;
		return ;
	}
	table_header();
	for (int i = 0; i < objectCount; i++)
	{
		if (i >= 8)
			break;
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		std::cout << std::right << std::setw(10) << _format(this->contacts[i].getFirstName()) << "|";
		std::cout << std::right << std::setw(10) << _format(this->contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << _format(this->contacts[i].getNickName()) << "|" << std::endl;
		std::cout << " " << std::right << std::setw(10) << "-------------------------------------------" << "\n";
	}
	std::cout << "enter idx of the contact that u need: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		exit(0);
	if (check_digit(str))
	{
		idx = std::atoi(str.c_str());
		if (idx > 0 && idx < objectCount + 1 && idx <= 8)
		{
			std::string str(90, '-');
			std::cout << " " << str << "\n";
			std::cout << "|" << std::right << std::setw(14) << "index" << "|";
			std::cout << std::right << std::setw(14) << "FirstName" << "|";
			std::cout << std::right << std::setw(14) << "LastName" << "|";
			std::cout << std::right << std::setw(14) << "NickName" << "|";
			std::cout << std::right << std::setw(14) << "phone number" << "|";
			std::cout << std::right << std::setw(14) << "darkest secret" << "|" << std::endl;
			std::cout << " " << str << "\n";
		
			std::cout << "|" << std::right << std::setw(14) << idx << "|";
			std::cout << std::right << std::setw(14) << _format(this->contacts[idx - 1].getFirstName()) << "|";
			std::cout << std::right << std::setw(14) << _format(this->contacts[idx - 1].getLastName()) << "|";
			std::cout << std::right << std::setw(14) << _format(this->contacts[idx - 1].getNickName()) << "|";
			std::cout << std::right << std::setw(14) << _format(this->contacts[idx - 1].getPhoneNumber()) << "|";
			std::cout << std::right << std::setw(14) << _format(this->contacts[idx - 1].getDarkestSecret()) << "|" << std::endl;
			std::cout << " " << str << "\n";
		}
		else
			std::cout << "warning: index out of range!!" << std::endl;
	}	
	else
		std::cout << "input is not a digit!!\n";
}
