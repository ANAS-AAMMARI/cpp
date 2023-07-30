/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:57:49 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/29 16:32:13 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void)
{
    
    BitcoinExchange b("data.csv");
    std::cout << "size " << b.getSize()<< std::endl;
    std::cout << "value " << b.getValue("2022-03-29") << std::endl;
    return (0);
}