/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:04:29 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/15 14:22:31 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>

class Span
{
    std::list<int> lst;
    unsigned int n;
    Span(void);
    typedef std::list<int>::iterator iterator;

public:
    Span(const unsigned int n);
    Span(const Span &src);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(int nbr);
    void addNumber(iterator begin, iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    class outOfRangeException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class lowSizeException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif