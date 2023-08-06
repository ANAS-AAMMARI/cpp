/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:53:31 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/05 18:38:28 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>


class RPN
{
    std::stack<double>  stack;
    public:
        RPN(void);
        RPN(const RPN & src);
        ~RPN();
        RPN & operator=(const RPN & rhs);
        void    parse(std::string str);
};
#endif