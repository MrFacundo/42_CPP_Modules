/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:46:36 by facu              #+#    #+#             */
/*   Updated: 2023/12/17 12:19:29 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
	: contactsCount(0) {}

bool PhoneBook::addContact(const Contact& contact)
{
	if (contactsCount >= MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			contacts[i] = contacts[i + 1];
		contactsCount--;
	}
	contacts[contactsCount++] = contact;
	return (true);
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
	}
}

void	PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int	PhoneBook::getContactsCount(void) const
{
	return contactsCount;
}


std::string PhoneBook::truncateString(const std::string& str, std::string::size_type width) const
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}