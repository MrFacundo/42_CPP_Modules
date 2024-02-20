/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:51:58 by facu              #+#    #+#             */
/*   Updated: 2023/12/14 16:36:37 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(const std::string &firstName,
				const std::string &lastName,
				const std::string &nickname,
				const std::string &phoneNumber,
				const std::string &darkestSecret)
				:
				firstName(firstName),
				lastName(lastName),
				nickname(nickname),
				phoneNumber(phoneNumber),
				darkestSecret(darkestSecret) {}

std::string Contact::getFirstName(void) const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}