/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:26 by aaammari          #+#    #+#             */
/*   Updated: 2023/05/22 17:01:49 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip> 
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];
		static int objectCount;
	
	public: //Constructor and Destructor
		PhoneBook();
		~PhoneBook();
	
	/* methodes*/
	public:
		void ADD(void);
		void SEARCH(void);
		
};

#endif