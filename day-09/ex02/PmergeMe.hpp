/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:30:28 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/13 11:25:12 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <utility>
#include <ctime>

class PmergeMe
{
    std::vector<std::pair<int, int> > vec2;
    std::vector<int> vec;
    std::vector< long long> jacob;
    std::vector< long long> combination;
    std::deque<int> deque;
    std::deque<std::pair<int, int> > dequePair;
    std::deque< long long> jacobDeque;
    std::deque< long long> combinationDeque;
    double timeVec;
    double timeDeque;
    public:
        static int Struggler;
        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe();
        PmergeMe & operator=(const PmergeMe & rhs);
        bool parse(std::string str);
        // vector implementation
        std::vector<int> const & getVec(void) const;
        void printVec(std::vector<int> vec, std::string str);
        void fillVecPair(void);
        void printVecPair(void);
        void insertionSort(void);
        long long jacobsthal(int n);
        void generateCombination(void);
        void makeJacob(void);
        int binarySearch(int l, int r, int x);
        void fordJohnson(void);
        // deque inplementation
        void fillDequePair(void);
        void printDequePair(void);
        void insertionSortDeque(void);
        void fordJohnsonDeque(void);
        void printDeque(void);
        void generateCombinationDeque(void);
        void makeJacobDeque(void);
        int binarySearchDeque(int l, int r, int x);
        
        // function for both implementations vector and deque
        void mergeInsertionSort(void);
};



#endif