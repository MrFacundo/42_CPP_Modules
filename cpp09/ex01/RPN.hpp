/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:45:24 by facu              #+#    #+#             */
/*   Updated: 2024/05/20 17:37:06 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <sstream>

class RPN {
    public:
        RPN(std::string const &str);
        RPN(RPN const &src);
        ~RPN();
        void display();
    private:
        std::stack<int> operation;
        std::string str;
        void calculate();
        int result;
};

#endif