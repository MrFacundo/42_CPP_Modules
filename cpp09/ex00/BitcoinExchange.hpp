/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:15:11 by ftroiter          #+#    #+#             */
/*   Updated: 2024/05/09 00:00:09 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>

struct Transaction
{
	std::string date;
	float value;
	std::string error;
};

struct Price
{
	std::string date;
	float value;
};

class BitcoinExchange
{
public:
	// CONSTRUCTORS AND DESTRUCTORS
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);
	
	// OPERATORS
	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	// MEMBER FUNCTIONS
	void loadPrices(std::string const &filename);
	void loadTransactions(std::string const &filename);
	void printValues(void) const;

	// GETTERS
	std::unordered_map<std::string, float> getValues() const;
	std::vector<Transaction> getTransactions() const;
	std::vector<Price> getPrices() const;
	
	// EXCEPTIONS
	class PricesParsingException : public std::exception
	{
	public:
		PricesParsingException(const std::string &message) : message("PricesParsingException: " + message) {}
		virtual const char *what() const throw()
		{
			return message.c_str();
		}

	private:
		std::string message;
	};
	class TransactionsParsingException : public std::exception
	{
	public:
		TransactionsParsingException(const std::string &message) : message("TransactionsParsingException: " + message) {}
		virtual const char *what() const throw()
		{
			return message.c_str();
		}

	private:
		std::string message;
	};
	class BadInputException : public std::exception
	{
	public:
		BadInputException(const std::string &message) : message("BadInputException: " + message) {}
		virtual const char *what() const throw()
		{
			return message.c_str();
		}

	private:
		std::string message;
	};
	class BadDateException : public std::exception
	{
	public:
		BadDateException(const std::string &message) : message("BadDateException: " + message) {}
		virtual const char *what() const throw()
		{
			return message.c_str();
		}

	private:
		std::string message;
	};

private:
	std::unordered_map<std::string, float> values;
	std::vector<Transaction> transactions;
	std::vector<Price> prices;
	// MEMBER FUNCTIONS
	void updateValues(void);
	
};

#endif