/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:14 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/30 14:03:20 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    setData(filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
        this->data = src.data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

int BitcoinExchange::getSize(void) const
{
    return (data.size());
}

bool checkDate(const std::string &date)
{
    size_t i = 0;
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    while (i < date.length())
    {
        if (i != 4 && i != 7)
            if (std::isdigit(date[i]) == 0)
                return (false);
        i++;
    }
    struct tm tm;
    tm.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
    tm.tm_mon = std::atoi(date.substr(5, 2).c_str()) - 1;
    tm.tm_mday = std::atoi(date.substr(8, 2).c_str());
    if (mktime(&tm) == -1)
        return (false);
    return (true);
}

bool checkValue(std::string const &value)
{
    size_t i = 0;
    int dot = 0;
    if (value.length() == 0)
        return (false);
    while (i < value.length())
    {
        if (value[i] == '.')
            dot++;
        else if (std::isdigit(value[i]) == 0)
            return (false);
        i++;
    }
    if (dot > 1)
        return (false);
    return (true);
}

void removeSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
}

void BitcoinExchange::setData(std::string const &filename)
{
    std::ifstream file(filename);
    std::string line;
    std::string date;
    std::string value;
    int i = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::getline(ss, date, ',');
            std::getline(ss, value);
            if (i == 0)
            {
                i++;
                continue;
            }
            std::cout << date << " " << value << std::endl;
            removeSpaces(date);
            removeSpaces(value);
            if (!checkDate(date) || !checkValue(value))
            {
                std::cout << "Invalid date or value." << std::endl;
                continue;
            }
            data[date] = std::atof(value.c_str());
            i++;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        exit(1);
    }
}

double BitcoinExchange::getValue(std::string const &date) const
{
   std::map<std::string, double>::const_iterator it = data.find(date);
    if (it != data.end())
        return (it->second);
    else
        return (-1);
}

bool checkLine(std::string const &line)
{
    if (line.length() == 0)
        return (false);
    if (line.find_first_of('|') == std::string::npos || line.find_last_of('|') != 11  || line.find_last_of('|') != 11)
        return (false);
    size_t pos = line.find_first_of('|');
    if (line[10] != ' ' || line[10] != '\t' || line[12] != ' ' || line[12] != '\t')
        return (false);
    return (true);
}

void BitcoinExchange::readInput(std::string const &filename)
{
    if (filename.length() == 0)
    {
        std::cout << "No filename given." << std::endl;
        exit(1);
    }
    double val;
    std::ifstream file(filename);
    std::string line;
    std::string date;
    std::string value;
    int i = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (!checkLine(line))
            {
                std::cout << "Invalid line." << std::endl;
                continue;
            }
            std::stringstream ss(line);
            std::getline(ss, date, '|');
            std::getline(ss, value);
            if (i == 0)
            {
                i++;
                continue;
            }
            removeSpaces(date);
            removeSpaces(value);
            if (!checkDate(date) || !checkValue(value))
            {
                std::cout << "Invalid date or value." << std::endl;
                continue;
            }
            val = std::atof(value.c_str());
            if (val < 0 || val > 1000)
            {
                std::cout << "Invalid value." << std::endl;
                continue;
            }
            if (this->getValue(date) != -1)
            {
                std::cout << date << " => " << this->getValue(date) << std::endl;
            }
            i++;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        exit(1);
    }
}