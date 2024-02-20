/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:08:57 by facu              #+#    #+#             */
/*   Updated: 2024/01/18 16:59:23 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
    typedef void (Harl::*ComplaintFunction)();
    const int numComplaints = 4;
    const char* complaintLevels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    ComplaintFunction complaintFunctions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < numComplaints; ++i) {
        if (level == complaintLevels[i]) {
            (this->*complaintFunctions[i])();
            return;
        }
    }

    std::cout << "Better not complain about that..." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This castle is in UNACCEPTABLE CONDITION!" << std::endl;
}