/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:15:11 by ftroiter          #+#    #+#             */
/*   Updated: 2024/05/20 10:46:44 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange &src);

	void display() const;

private:
	BitcoinExchange();

	void filetoMap(std::ifstream &file);
	std::string filename;
	std::map<std::string, float> exchangeRate;
	
	float getRate(const std::string &date) const;
	float getValue(const std::string &date, float amount) const;
	void printTransactionValue(const std::string &date, float amount) const;
	bool isDateValid(const std::string &date) const;
};

#endif