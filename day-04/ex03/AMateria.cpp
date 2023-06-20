/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:04:43 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 13:15:17 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria & src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

AMateria & AMateria::operator=(const AMateria & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
