/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:53:11 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/08 18:52:29 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::Struggler = -1;

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

void PmergeMe::fillVecPair(void)
{
    std::pair<int, int> pair;
    
    if (vec.size() % 2 != 0)
    {
        PmergeMe::Struggler = vec[vec.size() - 1];
        vec.pop_back();
    }
    for(size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
        {
            pair.first = vec[i + 1];
            pair.second = vec[i];
        }
        else
        {
            pair.first = vec[i];
            pair.second = vec[i + 1];
        }
        vec2.push_back(pair);
    }
}

bool PmergeMe::parse(std::string str)
{
    std::string tmp;
    std::stringstream ss(str);
    int nbr;
    std::string str2;
    while (ss >> tmp)
    {
        if (tmp[0] == '-' || tmp[0] == '+')
            str2 = tmp.substr(1);
        else
            str2 = tmp;
        if (str2.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Error: " << tmp << " is not a number" << std::endl;
            return (false);
        }
        nbr = std::atoi(tmp.c_str());
        if (nbr < 0)
        {
            std::cout << "Error: " << nbr << " is negative" << std::endl;
            return (false);
        }
        vec.push_back(std::atoi(tmp.c_str()));
    }
    return (true);
}

void PmergeMe::printVecPair(void)
{
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); i++)
    {
        std::cout << "(" << vec2[i].first << ", " << vec2[i].second << ") ";
    }
    std::cout << std::endl;
}
