/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:07 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/13 11:17:28 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
   if (ac == 1)
    {
        std::cout << "Error: no arguments" << std::endl;
        return (0);
    }
    PmergeMe p;
    for (int i = 1; i < ac; i++)
        if (p.parse(av[i]) == false)
            return (1);
    if (p.getVec().size() <= 1)
    {
        std::cout << "Error: not enough numbers" << std::endl;
        return (false);
    }
    p.mergeInsertionSort();
    return (0);
}