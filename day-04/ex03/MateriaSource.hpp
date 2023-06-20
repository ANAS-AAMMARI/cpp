/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:05:02 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/20 15:22:13 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materia[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &src);
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif