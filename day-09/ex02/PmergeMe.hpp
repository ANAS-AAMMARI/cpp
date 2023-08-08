/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:30:28 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/07 18:33:13 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>

class PmergeMe
{
    std::vector<int> vec;
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe();
        PmergeMe & operator=(const PmergeMe & rhs);
        void parse(std::string str);
        std::vector<int> const & getVec(void) const;
};



#endif