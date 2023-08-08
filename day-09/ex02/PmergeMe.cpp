/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:53:11 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/07 18:32:36 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe & src)
{
    *this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe & PmergeMe::operator=(const PmergeMe & rhs)
{
    if (this != &rhs)
    {
        this->vec = rhs.vec;
    }
    return (*this);
}

const std::vector<int> & PmergeMe::getVec(void) const
{
    return (this->vec);
}

void PmergeMe::parse(std::string str)
{
    std::string tmp;
    std::stringstream ss(str);
    int nbr;
    while (ss >> tmp)
    {
        if (tmp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Error: " << tmp << " is not a number" << std::endl;
            return ;
        }
        nbr = std::atoi(tmp.c_str());
        if (nbr < 0)
        {
            std::cout << "Error: " << nbr << " is negative" << std::endl;
            return ;
        }
        vec.push_back(std::atoi(tmp.c_str()));
    }
}