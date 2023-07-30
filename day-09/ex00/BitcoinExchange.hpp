/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:20 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/30 13:53:55 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>

class BitcoinExchange
{
    std::map<std::string, double> data;
    BitcoinExchange(void);

public:
    BitcoinExchange(std::string filename);
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange(void);
    void setData(const std::string &filename);
    double getValue(const std::string &date) const;
    int getSize(void) const;
    void readInput(std::string const &filename);
};
#endif