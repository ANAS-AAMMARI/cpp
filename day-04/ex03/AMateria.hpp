/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:56:27 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 15:24:17 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria & src);
		virtual ~AMateria(void);
		AMateria & operator=(const AMateria & rhs);
		std::string const & getType(void) const; //Returns the materia type
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
	protected:
		AMateria(void);
		std::string _type;
};

#endif
