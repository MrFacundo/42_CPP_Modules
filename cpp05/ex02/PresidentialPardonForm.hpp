/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:26:20 by facu              #+#    #+#             */
/*   Updated: 2024/04/15 17:47:21 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <math.h>

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm(void);
		std::string target;
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		
		void execute(const Bureaucrat &executor) const;
};

#endif