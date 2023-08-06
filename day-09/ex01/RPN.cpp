/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:32:41 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/06 12:16:02 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN & src)
{
    *this = src;
}

RPN::~RPN()
{
}

RPN & RPN::operator=(const RPN & rhs)
{
    if (this != &rhs)
        this->stack = rhs.stack;
    return (*this);
}

void RPN::parse(std::string str)
{
    std::string::iterator it = str.begin();
    std::string::iterator ite = str.end();
    double nb;
    while (it != ite)
    {
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error: Not enough numbers in stack" << std::endl;
                return ;
            }
            double nb1 = stack.top();
            stack.pop();
            double nb2 = stack.top();
            stack.pop();
            if (*it == '+')
                stack.push(nb1 + nb2);
            else if (*it == '-')
                stack.push(nb2 - nb1);
            else if (*it == '*')
                stack.push(nb1 * nb2);
            else if (*it == '/')
            {
                if (nb1 == 0)
                {
                    std::cout << "Error: division by 0" << std::endl;
                    return ;
                }
                stack.push(nb2 / nb1);
            }   
        }
        else if (*it >= '0' && *it <= '9')
        {
            std::string nb_str = "";
            nb_str += *it;
            nb = std::atof(nb_str.c_str());
            stack.push(nb);
        }
        else if (*it != ' ')
        {
            std::cout << "Error: invalid character" << std::endl;
            return ;
        }
       it++;
    }
    if (stack.size() != 1)
        std::cout << "Error: too many numbers in stack" << std::endl;
    else
        std::cout << stack.top() << std::endl;
}