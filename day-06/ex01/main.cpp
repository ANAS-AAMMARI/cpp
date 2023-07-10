/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:21:14 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/10 11:26:20 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* data = new Data;
	data->rnd_str = "Hello World!";
	data->rand_int = 1337;

	uintptr_t serialized = Serializer::serialize(data);
	// std::cout << serialized << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "rnd_str: " << deserialized->rnd_str << std::endl;
	std::cout << "rand_int: " << deserialized->rand_int << std::endl;

	delete data;
	return (0);
}