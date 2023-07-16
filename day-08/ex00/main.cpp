/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:02:54 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/15 10:57:21 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(i);
        lst.push_back(i);
    }
    
    // for (size_t i = 0; i < vec.size(); i++)
    //     std::cout << "vec[" << i << "] = " << vec.at(i) << std::endl;
    std::vector<int>::iterator itr;
    for (itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
    std::cout << easyfind(vec, 5) << std::endl;
    std::cout << easyfind(lst, 45) << std::endl;
    
}