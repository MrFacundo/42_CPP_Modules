/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:18 by facu              #+#    #+#             */
/*   Updated: 2024/05/17 15:11:35 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CONSTRUCTORS AND DESTRUCTORS
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// OPERATORS
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->values = rhs.getValues();
		this->transactions = rhs.getTransactions();
		this->prices = rhs.getPrices();
	}
	return *this;
}

// GETTERS
std::map<std::string, std::pair<float, float> > BitcoinExchange::getValues() const
{
	return this->values;
}

std::vector<Transaction> BitcoinExchange::getTransactions() const
{
	return this->transactions;
}

std::vector<Price> BitcoinExchange::getPrices() const
{
	return this->prices;
}

// MEMBER FUNCTIONS
void BitcoinExchange::loadPrices(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::string date;
	float value;
	std::vector<Price> prices;

	if (!file.is_open())
		throw PricesParsingException("Error: Could not open file");

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!std::getline(iss, date, ',') || !(iss >> value))
			throw PricesParsingException("Error: Could not parse file");
		Price price;
		price.date = date;
		price.value = value;
		prices.push_back(price);
	}
	this->prices = prices;
}

bool BitcoinExchange::parseLine(const std::string& line, Transaction& transaction)
{
    std::istringstream iss(line);
    std::string date_str;
    float value;

    if (!std::getline(iss, date_str, '|') || !(iss >> value))
    {
        transaction.error = "Error: Bad input";
        return false;
    }
	
    struct tm date = {};
    sscanf(date_str.c_str(), "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday);
    date.tm_year -= 1900; // Years since 1900
    date.tm_mon -= 1; // Months since January

    if (date.tm_year + 1900 < 2009 || date.tm_mon + 1 < 1 || date.tm_mon + 1 > 12 || date.tm_mday < 1 || date.tm_mday > 31)
    {
        transaction.error = "Error: Invalid date";
        return false;
    }

    if (value < 0)
    {
        transaction.error = "Error: Not a positive number";
        return false;
    }

    if (value > INT_MAX)
    {
        transaction.error = "Error: Too large a number";
        return false;
    }

    transaction.date = date_str;
    transaction.value = value;

    return true;
}

void BitcoinExchange::loadTransactions(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::vector<Transaction> transactions;

	if (!file.is_open())
		throw PricesParsingException("Could not open file");

	std::getline(file, line);
	while (std::getline(file, line))
	{
		Transaction t;
		if (!parseLine(line, t))
		{
			transactions.push_back(t);
			continue;
		}
		transactions.push_back(t);
	}
	this->transactions = transactions;
}

bool comparePrices(const Price &a, const Price &b)
{
    return a.date < b.date;
}

void BitcoinExchange::updateValues(void)
{
    std::map<std::string, std::pair<float, float> > values;
    std::sort(this->prices.begin(), this->prices.end(), comparePrices);

    for (std::vector<Transaction>::iterator transaction = this->transactions.begin(); transaction != this->transactions.end(); ++transaction)
    {
        if (transaction->error.empty())
        {
            std::vector<Price>::iterator it;
            for (it = this->prices.begin(); it != this->prices.end(); ++it)
            {
                if (it->date >= transaction->date)
                {
                    break;
                }
            }
            if (it != this->prices.begin())
            {
                --it;
                values[transaction->date] = std::make_pair(transaction->value, transaction->value * it->value);
            }
            else
            {
                values["No matching lower date found for " + transaction->date] = std::make_pair(0.0f, 0.0f);
            }
        }
        else
        {
            values[transaction->error] = std::make_pair(0.0f, 0.0f);
        }
    }
    this->values = values;
}

void BitcoinExchange::printValues(void)
{
	updateValues();
	for (std::map<std::string, std::pair<float, float> >::iterator value = this->values.begin(); value != this->values.end(); ++value)
	{
		if (value->first.size() >= 7 && value->first.substr(0, 7) == "Error: ")
			std::cout << value->first << std::endl;
		else
			std::cout << value->first << " => " << value->second.first << " => " << value->second.second << std::endl;
	}
}
