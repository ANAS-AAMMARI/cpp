/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:05:28 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/11 11:13:54 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

template <typename T>
void	print(T const &x)
{
	std::cout << x << " ";
}

int main(void)
{
	int		intArr[5] = {1, 2, 3, 4, 5};
	char	charArr[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "intArray: ";
	iter(intArr, 5, print);
	std::cout << std::endl;
	std::cout << "charArray: ";
	iter(charArr, 5, print);
	std::cout << std::endl;
	return (0);
}
