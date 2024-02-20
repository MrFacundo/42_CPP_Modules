/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:52:13 by facu              #+#    #+#             */
/*   Updated: 2023/12/17 12:20:33 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
  public:
	Contact(void);
	Contact(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;	
};

#endif