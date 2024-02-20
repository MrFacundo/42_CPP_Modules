/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:23:52 by facu              #+#    #+#             */
/*   Updated: 2023/12/16 14:27:53 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

template <typename T> void getInput(T &input, const std::string &prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << "EOF encountered. Exiting program." << std::endl;
			exit(0);
		}
		else
		{
			return ;
		}
	}
}

bool	isValidPhoneNumber(const std::string &phoneNumber)
{
	for (char digit : phoneNumber)
	{
		if (!std::isdigit(digit))
		{
			return (false);
		}
	}
	return (true);
}

int	main(void)
{
	PhoneBook	phoneBook;
	bool		validPhoneNumber;
	int			index;

	while (true)
	{
		std::string command;
		getInput(command, "Enter command (ADD, SEARCH, EXIT): ");
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			std::string firstName, lastName, nickname, phoneNumber,
				darkestSecret;
			getInput(firstName, "Enter first name: ");
			getInput(lastName, "Enter last name: ");
			getInput(nickname, "Enter nickname: ");
			while (true)
			{
				getInput(phoneNumber, "Enter phone number: ");
				validPhoneNumber = isValidPhoneNumber(phoneNumber);
				if (validPhoneNumber)
					break ;
				std::cout << "Invalid phone number. ";
			}
			getInput(darkestSecret, "Enter darkest secret: ");
			Contact newContact(firstName, lastName, nickname, phoneNumber,
				darkestSecret);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			if (phoneBook.getContactsCount() == 0)
				continue ;
			getInput(index, "Enter index: ");
			if (index < 0 || index >= phoneBook.getContactsCount()
				|| std::cin.fail())
			{
				std::cout << "Invalid index" << std::endl;
				std::cin.clear();
				continue ;
			}
			phoneBook.displayContactDetails(index);
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
