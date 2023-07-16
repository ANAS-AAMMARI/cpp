/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:29:43 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/15 14:30:29 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack<T>(void) : std::stack<T>() {}
        MutantStack<T>(MutantStack<T> const & src) : std::stack<T>(src) {}
        virtual ~MutantStack<T>(void) {}
        MutantStack<T> & operator=(MutantStack<T> const & rhs) {this->c = rhs.c; return (*this);}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void) {return (this->c.begin());}
        iterator end(void) {return (this->c.end());}
};

#endif