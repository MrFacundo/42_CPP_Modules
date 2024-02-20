/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:48:38 by facu              #+#    #+#             */
/*   Updated: 2023/12/21 15:34:16 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class PhoneBook
{
  public:
	PhoneBook(void);
	bool addContact(const Contact& contact);
	void displayContacts(void) const;
	void displayContactDetails(int index) const;
	int getContactsCount(void) const;

  private:
	std::string truncateString(const std::string& str, std::string::size_type width) const;
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int contactsCount;
};

#endif