/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:13:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 10:30:55 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure & src);
		virtual ~Cure(void);
		Cure & operator=(const Cure & rhs);
		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif