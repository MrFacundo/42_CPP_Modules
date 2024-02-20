/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:08:57 by facu              #+#    #+#             */
/*   Updated: 2024/01/18 17:00:28 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum ComplaintLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
};

void Harl::complain(std::string level)
{
    ComplaintLevel complaintLevel;

    if (level == "DEBUG") complaintLevel = DEBUG;
    else if (level == "INFO") complaintLevel = INFO;
    else if (level == "WARNING") complaintLevel = WARNING;
    else if (level == "ERROR") complaintLevel = ERROR;
    else complaintLevel = INVALID;

    switch (complaintLevel)
    {
        case DEBUG:
            debug();
        case INFO:
            info();
        case WARNING:
            warning();
        case ERROR:
            error();
            break;
        default:
            std::cout << "Better not complain about that..." << std::endl;
    }
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