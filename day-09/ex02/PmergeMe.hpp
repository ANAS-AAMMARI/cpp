/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:30:28 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/08 18:51:39 by aaammari         ###   ########.fr       */
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

class PmergeMe
{
    std::vector<std::pair<int, int> > vec2;
    std::vector<int> vec;
    public:
        static int Struggler;
        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe();
        PmergeMe & operator=(const PmergeMe & rhs);
        bool parse(std::string str);
        std::vector<int> const & getVec(void) const;
        void fillVecPair(void);
        void printVecPair(void);
};



#endif