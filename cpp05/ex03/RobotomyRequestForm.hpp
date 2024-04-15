/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:56:17 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 17:48:12 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <math.h>

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);
		std::string target;
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		
		void execute(const Bureaucrat &executor) const;
};

#endif