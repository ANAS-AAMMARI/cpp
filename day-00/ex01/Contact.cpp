/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:33 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/20 19:29:10 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName; 
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::~Contact()
{
	
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickName() const
{
	return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}
