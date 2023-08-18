/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:22:50 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/18 18:24:20 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int n) : n(n)
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->lst = other.lst;
        this->n = other.n;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
    if (lst.size() < n)
        lst.push_back(nbr);
    else
        throw Span::outOfRangeException();
}

void Span::addNumber(iterator begin, iterator end)
{
    if (lst.size() + std::distance(begin, end) <= n)
        lst.insert(lst.end(), begin, end);
    else
        throw Span::outOfRangeException();
}

int Span::shortestSpan() const
{
    if (this->lst.size() <= 1 || this->n <= 1)
        throw Span::lowSizeException();
    std::list<int> tmp = this->lst;
    std::list<int>::iterator it = tmp.begin();
    tmp.sort();
    int min = *it;
    int diff = std::abs(*(++it) - min);
    while (it != tmp.end())
    {
        if (diff > std::abs((*it - min)))
            diff = std::abs(*it - min);
        min = *it;
        it++;
    }
    return (diff);
}

int Span::longestSpan() const
{
    if (this->lst.size() <= 1 || this->n <= 1)
        throw Span::lowSizeException();
    return (*std::max_element(this->lst.begin(), this->lst.end()) - *std::min_element(this->lst.begin(), this->lst.end()));
}

const char *Span::outOfRangeException::what() const throw()
{
    return ("Span::addNumber: list is full");
}

const char *Span::lowSizeException::what() const throw()
{
    return ("Exception: list is empty or have just one element");
}
