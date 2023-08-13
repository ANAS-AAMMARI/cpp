/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:14 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/13 18:31:31 by aaammari         ###   ########.fr       */
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

bool checkDate(const std::string date)
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
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 1900 || year > 9999)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31 || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        return (false);
    if (month == 2)
    {
       if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
       {
           if (day > 29)
               return (false);
       }
       else if (day > 28)
           return (false);
    }
    return (true);
}

bool checkValue(std::string const value)
{
    size_t i = 0;
    int dot = 0;
    if (value.length() == 0)
        return (false);
    if (value[0] == '-' || value[0] == '+')
        i++;
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
            removeSpaces(date);
            removeSpaces(value);
            if (checkDate(date) == false)
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (checkValue(value) == false)
            {
                std::cerr << "Error: bad input => " << value << std::endl;
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

// double BitcoinExchange::getValue(std::string const &date) const
// {
//     if (this->data.empty())
//         return (-1);
//     std::map<std::string, double>::const_iterator it = data.find(date);
//     if (it != data.end())
//         return (it->second);
//     else
//         return (-1);
// }

// std::string BitcoinExchange::getMinDate(const std::string &date) const
// {
//     if (this->data.size() == 0)
//         return ("");
//     std::map<std::string, double>::const_iterator it = data.begin();
//     std::string minDate = it->first;
//     while (it != data.end())
//     {
//         if (it->first < date && it->first > minDate)
//             minDate = it->first;
//         it++;
//     }
//     return (minDate);
// }

double BitcoinExchange::getMinDate(const std::string &date) const
{
    if (this->data.size() == 0)
        return (-1);
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date)
        return (it->second);
    else if (it != data.begin())
        return ((--it)->second);
    return (-1);
}

bool checkLine(std::string const &line)
{
    if (line.length() == 0)
        return (false);
    if (line.find_first_of('|') == std::string::npos || line.find_last_of('|') != 11  || line.find_last_of('|') != 11)
        return (false);
    if (line[10] != ' ' && line[10] != '\t' && line[12] != ' ' && line[12] != '\t')
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
        getline(file, line, '\0');
        if (line.empty())
        {
            std::cout << "Empty file." << std::endl;
            exit(1);
        }
        while (getline(file, line))
        {
            if (line.empty())
                continue;
            if ((line.find("date") == std::string::npos || line.find("value") == std::string::npos) && i == 0)
            {
                std::cout << "need title of file => \"date | value\"" << std::endl;
                i++;
                continue;
            }
            if ((line.find("date") != std::string::npos || line.find("value") != std::string::npos) && i == 0)
            {
                i++;
                continue;
            }
            if (!checkLine(line))
            {
                std::cout << "bad intput => " << line << std::endl;
                continue;
            }
            std::stringstream ss(line);
            std::getline(ss, date, '|');
            std::getline(ss, value);
            removeSpaces(date);
            removeSpaces(value);
            if (!checkDate(date))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (!checkValue(value))
            {
                std::cout << "Error: bad input => " << value << std::endl;
                continue;
            }
            val = std::atof(value.c_str());
            if (val < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else if (val > 1000)
            {
                std::cout << "Error: too large number." << std::endl;
                continue;
            }
            if (this->getMinDate(date) != -1)
                std::cout << date << " => " << val << " = " << val * this->getMinDate(date) << std::endl;
            else
                std::cout << "Error: no date found." << std::endl;
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