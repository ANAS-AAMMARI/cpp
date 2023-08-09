/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:53:11 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/09 18:56:34 by aaammari         ###   ########.fr       */
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

int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

int PmergeMe::binarySearch(int l, int r, int x)
{
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (this->vec[m] == x)
            return m;
        if (this->vec[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

void PmergeMe::insertionSort(void)
{
    size_t i, j, len = vec2.size();
    std::pair<int, int> tmp;
    for (i = 1; i < len; i++)
    {
        tmp = vec2[i];
        j = i;
        while (j > 0 && vec2[j - 1].first > tmp.first)
        {
            vec2[j] = vec2[j - 1];
            j--;
        }
        vec2[j] = tmp;
    }
}

void PmergeMe::fordJohnson(void)
{
    vec.clear();
    for(size_t i = 0; i < vec2.size(); i++)
        vec.push_back(vec2[i].first);
    vec.push_back(vec2[vec2.size() - 1].second);
    vec2.pop_back();
    printVec();
    int len = vec2.size();
    int jac;
    bool isJac = false;
    while (--len >= 0)
    {
        if (!isJac)
        {
            jac = jacobsthal(len);
            isJac = true;
        }
        else
            jac--;   
        int index = binarySearch(0, vec.size() - 1, vec2[jac].second);
        if (vec2[jac].second == 3)
        {
            printVec();
            std::cout << "index: " << index << " " << jac << std::endl;
        }   
        vec.insert(vec.begin() + index, vec2[len].second);
    }
    if (PmergeMe::Struggler != -1)
    {
        int index = binarySearch(0, vec.size() - 1, PmergeMe::Struggler);
        vec.insert(vec.begin() + index, PmergeMe::Struggler);
    }
}

void PmergeMe::printVec(void)
{
    std::cout << "before: ";
    std::vector<int>::const_iterator it = this->getVec().begin();
    std::vector<int>::const_iterator ite = this->getVec().end();
    while (it != ite)
    {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
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
