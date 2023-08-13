/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:53:11 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/13 11:49:17 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::Struggler = -1;

PmergeMe::PmergeMe(void)
{
    this->timeDeque = 0;
    this->timeVec = 0;
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
        this->vec2 = rhs.vec2;
        this->timeDeque = rhs.timeDeque;
        this->timeVec = rhs.timeVec;
        this->deque = rhs.deque;
        this->dequePair = rhs.dequePair;
        this->jacob = rhs.jacob;
        this->combination = rhs.combination;
        this->jacobDeque = rhs.jacobDeque;
        this->combinationDeque = rhs.combinationDeque;
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
    clock_t start;
    clock_t end;
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
        start = clock();
        vec.push_back(nbr);
        end = clock();
        this->timeVec += (double)(end - start) * 1000000 / CLOCKS_PER_SEC;
        start = clock();
        deque.push_back(nbr);
        end = clock();
        this->timeDeque += (double)(end - start) * 1000000 / CLOCKS_PER_SEC;
    }
    return (true);
}

long long PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::makeJacob(void)
{
    long long jac;
    long long len = vec.size();
    size_t size = vec2.size();
    for (size_t i = 0; i < size + 10; i++)
    {
        jac = jacobsthal(i);
        if (jac > (len * 2))
            break;
        jacob.push_back(jac);
    }    
}

void PmergeMe::generateCombination(void)
{
    long long last = 1;
    makeJacob();
    for (size_t i = 3; i < jacob.size(); i++)
    {
        for (long long j = jacob[i]; j > last; j--)
            combination.push_back(j);
        last = jacob[i];
    }
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
        while (j > 0 && vec2[j - 1].second > tmp.second)
        {
            vec2[j] = vec2[j - 1];
            j--;
        }
        vec2[j] = tmp;
    }
    // std::cout << "Unsorted: \n";
}

void PmergeMe::fordJohnson(void)
{
    vec.clear();
    insertionSort();
    for(size_t i = 0; i < vec2.size(); i++)
        vec.push_back(vec2[i].second);
    vec.insert(vec.begin(), vec2[0].first);
    generateCombination();
    // std::cout << "Sorted: \n";
    size_t len = vec2.size();
    // std::cout << "Combination: ";
    // std::vector<long long>::const_iterator it = combination.begin();
    // std::vector<long long>::const_iterator ite = combination.end();
    // while (it != ite)
    // {
    //     std::cout << *it;
    //     if (++it != ite)
    //         std::cout << " ";
    // }
    // std::cout << std::endl;
    int index;
    size_t i = 0;
    while (i < len)
    {   
        if (combination[i] - 1 >= (long long)len)
        {
            i++;
            continue;
        }
        index = binarySearch(0, vec.size() - 1, vec2[combination[i] - 1].first);
        vec.insert(vec.begin() + index, vec2[combination[i] - 1].first);
        i++;
    }
    if (PmergeMe::Struggler != -1)
    {
        index = binarySearch(0, vec.size() - 1, PmergeMe::Struggler);
        vec.insert(vec.begin() + index, PmergeMe::Struggler);
    }
}

void PmergeMe::printVec(std::vector<int> vec, std::string str)
{
    std::cout << str;
    std::vector<int>::const_iterator it = vec.begin();
    std::vector<int>::const_iterator ite = vec.end();
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

// deque functions implementation ====================================================

void PmergeMe::fillDequePair(void)
{
    std::pair<int, int> pair;
    
    if (deque.size() % 2 != 0)
    {
        PmergeMe::Struggler = deque.back();
        deque.pop_back();
    }
    for(size_t i = 0; i < deque.size(); i += 2)
    {
        if (deque[i] > deque[i + 1])
        {
            pair.first = deque[i + 1];
            pair.second = deque[i];
        }
        else
        {
            pair.first = deque[i];
            pair.second = deque[i + 1];
        }
        dequePair.push_back(pair);
    }
}

void PmergeMe::insertionSortDeque(void)
{
    size_t i, j, len = dequePair.size();
    std::pair<int, int> tmp;
    for (i = 1; i < len; i++)
    {
        tmp = dequePair[i];
        j = i;
        while (j > 0 && dequePair[j - 1].second > tmp.second)
        {
            dequePair[j] = dequePair[j - 1];
            j--;
        }
        dequePair[j] = tmp;
    }
}

void PmergeMe::printDequePair(void)
{
    std::cout << "dequePair: ";
    for (size_t i = 0; i < dequePair.size(); i++)
    {
        std::cout << "(" << dequePair[i].first << ", " << dequePair[i].second << ") ";
    }
    std::cout << std::endl;
}

void PmergeMe::makeJacobDeque(void)
{
    long long jac;
    size_t size = dequePair.size();
    long long len = deque.size() * 2;
    for (size_t i = 0; i < size + 10; i++)
    {
        jac = jacobsthal(i);
        if (jac > len)
            break;
        jacobDeque.push_back(jac);
    }
}

void PmergeMe::generateCombinationDeque(void)
{
    long long last = 1;
    makeJacobDeque();
    for (size_t i = 3; i < jacobDeque.size(); i++)
    {
        for (long long j = jacobDeque[i]; j > last; j--)
            combinationDeque.push_back(j);
        last = jacobDeque[i];
    }
}

int PmergeMe::binarySearchDeque(int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (deque[mid] == x)
            return mid;
        if (deque[mid] > x)
            return binarySearchDeque(l, mid - 1, x);
        return binarySearchDeque(mid + 1, r, x);
    }
    return l;
}

void PmergeMe::fordJohnsonDeque(void)
{
    deque.clear();
    insertionSortDeque();
    for(size_t i = 0; i < dequePair.size(); i++)
        deque.push_back(dequePair[i].second);
    deque.insert(deque.begin(), dequePair[0].first);
    generateCombinationDeque();
    size_t len = dequePair.size();
    // std::cout << "Combination: ";
    // std::vector<long long>::const_iterator it = combination.begin();
    // std::vector<long long>::const_iterator ite = combination.end();
    // while (it != ite)
    // {
    //     std::cout << *it;
    //     if (++it != ite)
    //         std::cout << " ";
    // }
    // std::cout << std::endl;
    int index;
    size_t i = 0;
    while (i < len)
    {   
        if ((combinationDeque[i] - 1) >= (long long)len)
        {
            i++;
            continue;
        }
        index = binarySearchDeque(0, deque.size() - 1, dequePair[combinationDeque[i] - 1].first);
        // std::cout << "com: " << combinationDeque[i] - 1 << " value: " << dequePair[combinationDeque[i] - 1].first << " index: "<< index << std::endl;
        deque.insert(deque.begin() + index, dequePair[combinationDeque[i] - 1].first);
        i++;
    }
    if (PmergeMe::Struggler != -1)
    {
        index = binarySearchDeque(0, deque.size() - 1, PmergeMe::Struggler);
        deque.insert(deque.begin() + index, PmergeMe::Struggler);
    }
}

void PmergeMe::printDeque(void)
{
    std::cout << "after: ";
    std::deque<int>::const_iterator it = deque.begin();
    std::deque<int>::const_iterator ite = deque.end();
    while (it != ite)
    {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// function for both implementation ==========================================

void PmergeMe::mergeInsertionSort(void)
{
    this->printVec(this->getVec(), std::string("before: "));
    clock_t start = clock();
    this->fillVecPair();
    this->fordJohnson();
    clock_t end = clock();
    this->timeVec += static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;
    this->printVec(this->getVec(), std::string("after: "));
    start = clock();
    this->fillDequePair();
    this->fordJohnsonDeque();
    end = clock();
    this->timeDeque += static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector " << this->timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque " << this->timeDeque << " us" << std::endl;
}

