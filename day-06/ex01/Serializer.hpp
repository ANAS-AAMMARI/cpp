/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:52:20 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/10 08:26:10 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct data
{
	std::string rnd_str;
	int rand_int;
}Data;

class Serializer
{
	Serializer(void);
	Serializer(const Serializer & src);
	~Serializer(void);
	Serializer & operator=(const Serializer & rhs);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif