/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:33:18 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/18 16:30:06 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>


class Brain
{
	public:
		std::string ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain & src);
		Brain & operator=(const Brain & src);
};

# endif