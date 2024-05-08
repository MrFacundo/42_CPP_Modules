/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:18 by facu              #+#    #+#             */
/*   Updated: 2024/05/07 19:54:03 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <map>

class BitcoinExchange {
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		// OPERATORS
		BitcoinExchange& operator=(BitcoinExchange const &rhs);
		// MEMBER FUNCTIONS
		void loadDB(std::string const &filename);
		void loadInput(std::string const &filename);
		void printExchange(void);

		class DBParsingException : public std::exception {
			public:
				virtual const char* what(void) const throw()
				{
					return ("Error: DBParsingException");
				}
		};
		class BadInputException : public std::exception {
			public:
				virtual const char* what(void) const throw()
				{
					return ("Error: BadInputException");
				}
		};
		class BadValueException : public std::exception {
			public:
				virtual const char* what(void) const throw()
				{
					return ("Error: BadValueException");
				}
		};
		class BadDateException : public std::exception {
			public:
				virtual const char* what(void) const throw()
				{
					return ("Error: BadDateException");
				}
		};
	private:
		
};

#endif