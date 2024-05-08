/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:18 by facu              #+#    #+#             */
/*   Updated: 2024/05/08 23:08:46 by ftroiter         ###   ########.fr       */
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
		if (!(iss >> date >> value))
			throw PricesParsingException("Could not parse line");
		prices.push_back({date, value});
	}
	this->prices = prices;
}
