/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:54:40 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/14 11:11:05 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
bool easyfind(T ctr, int toFind)
{
    // if (std::find(ctr.begin(), ctr.end(), toFind) != ctr.end())
    //     return (true);
    // return (false);
    typename T::iterator itr;
    itr = std::find(ctr.begin(), ctr.end(), toFind);
    if (itr != ctr.end())
        return true;
    return false;
}

#endif