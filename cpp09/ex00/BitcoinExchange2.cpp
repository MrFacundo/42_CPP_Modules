/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange2.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:18 by facu              #+#    #+#             */
/*   Updated: 2024/05/20 11:39:05 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CONSTRUCTORS AND DESTRUCTORS
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename) : filename(filename)
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error(".csv file not found");
    filetoMap(file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {}

// OPERATORS
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        this->exchangeRate = rhs.exchangeRate;
        this->filename = rhs.filename;
    }
    return *this;
}

// MEMBER FUNCTIONS
void BitcoinExchange::filetoMap(std::ifstream &file)
{
    if (!file)
        throw std::runtime_error("Failed to parse exchange rate file");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::getline(ss, date, ',');
        if (date.size() != 10 || date[4] != '-' || date[7] != '-')
            throw std::runtime_error("Failed to parse exchange rate file");
        for (std::string::size_type i = 0; i < date.size(); ++i)
        {
            if (i == 4 || i == 7) continue;
            if (!isdigit(date[i]))
                throw std::runtime_error("Failed to parse exchange rate file");
        }
        double rate;
        if (!(ss >> rate))
            throw std::runtime_error("Failed to parse exchange rate file");
        if (rate < 0)
            throw std::runtime_error("Failed to parse exchange rate file");
        exchangeRate[date] = rate;
    }
}

float BitcoinExchange::getRate(const std::string &date) const
{
    if (exchangeRate.find(date) != exchangeRate.end())
        return exchangeRate.at(date);
    std::map<std::string, float>::const_iterator it = exchangeRate.lower_bound(date);
    if (it != exchangeRate.begin())
        return (--it)->second;
    else
    {
        return it->second;
    }
}

float BitcoinExchange::getValue(const std::string &date, float amount) const
{
    if (!amount)
        throw std::runtime_error("bad input => " + date);
    if (amount < 0)
        throw std::runtime_error("not a positive number.");
    if (amount > 1000)
        throw std::runtime_error("too large a number.");
    try
    {
        return amount * getRate(date);
    }
    catch (std::exception &e)
    {
        throw;
    }
}

void BitcoinExchange::printTransactionValue(const std::string &date, float amount) const
{
    float value;
    try
    {
        isDateValid(date);
        value = getValue(date, amount);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::cout << date << "=> " << amount << " = " << std::fixed << std::setprecision(2) << value << std::endl;
}

bool BitcoinExchange::isDateValid(const std::string &date) const
{
    if (date.size() != 10)
        throw std::runtime_error("Error: bad input => " + date);
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                throw std::runtime_error("bad input => " + date);
        }
        else
        {
            if (!isdigit(date[i]))
                throw std::runtime_error("bad input => " + date);
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2024)
        throw std::runtime_error("bad input => " + date);
    if (month < 1 || month > 12)
        throw std::runtime_error("bad input => " + date);
    if (day < 1 || day > 31)
        throw std::runtime_error("bad input => " + date);
    return true;
}

std::string rtrim(const std::string &s)
{
    std::string rs = s;
    rs.erase(std::find_if(rs.rbegin(), rs.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), rs.end());
    return rs;
}

void BitcoinExchange::display() const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File not found");
    std::string line;
    std::string date;
    float amount;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::getline(ss, date, '|');
        date = rtrim(date);
        ss >> amount;
        try
        {
            if (ss.fail())
                throw std::runtime_error("bad input => " + date);
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }
        printTransactionValue(date, amount);
    }
}