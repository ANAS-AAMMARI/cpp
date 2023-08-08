/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:07 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/08 18:58:06 by aaammari         ###   ########.fr       */
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
    p.getVec().begin();
    std::vector<int>::const_iterator it = p.getVec().cbegin();
    std::vector<int>::const_iterator ite = p.getVec().cend();
    while (it != ite)
    {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
        
    p.fillVecPair();
    p.printVecPair();
    return (0);
}