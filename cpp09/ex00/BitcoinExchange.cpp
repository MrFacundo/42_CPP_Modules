/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:18 by facu              #+#    #+#             */
/*   Updated: 2024/05/09 00:02:06 by ftroiter         ###   ########.fr       */
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

// MEMBER FUNCTIONS

void BitcoinExchange::loadPrices(std::string const &filename)
{
	std::ifstream file(filename);
	std::string line;
	std::string date;
	float value;
	std::vector<Price> prices;

	if (!file.is_open())
		throw PricesParsingException("Could not open file");

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!std::getline(iss, date, ',') || !(iss >> value))
			throw PricesParsingException("Could not parse line");
		prices.push_back({date, value});
	}
	this->prices = prices;
}


void BitcoinExchange::loadPrices(std::string const &filename)
{
	std::ifstream file(filename);
	std::string line;
	std::string date;
	std::string value_str;
	float value;
	std::vector<Price> prices;

	if (!file.is_open())
		throw PricesParsingException("Could not open file");

	// Skip the title line
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!std::getline(iss, date, '|') || !(iss >> value))
			throw PricesParsingException("Could not parse line");
		date.erase(0, date.find_first_not_of(' '));
		date.erase(date.find_last_not_of(' ') + 1);
		prices.push_back({date, value});
	}
	this->prices = prices;
}




void updateValues(std::vector<Transaction> transactions, std::vector<Price> prices, std::unordered_map<std::string, float> &values)
{
	for (std::vector<Transaction>::iterator it = transactions.begin(); it != transactions.end(); ++it)
	{
		float price = 0;
		for (std::vector<Price>::iterator pit = prices.begin(); pit != prices.end(); ++pit)
		{
			if (pit->date == it->date)
			{
				price = pit->value;
				break;
			}
		}
		if (price == 0)
		{
			it->error = "Could not find price for date " + it->date;
			continue;
		}
		if (values.find(it->from) == values.end())
			values[it->from] = 0;
		if (values.find(it->to) == values.end())
			values[it->to] = 0;
		values[it->from] -= it->amount * price;
		values[it->to] += it->amount * price;
	}
}
