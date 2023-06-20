/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:08:30 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 10:08:54 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice & src);
		virtual ~Ice(void);
		Ice & operator=(const Ice & rhs);
		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif