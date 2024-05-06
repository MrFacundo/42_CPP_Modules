/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/05/04 13:09:08 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void tryFind(T &container, typename T::value_type n, const std::string &container_name)
{
    try
    {
        std::cout << easyfind(container, n) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Element " << n << " not found in " << container_name << std::endl;
    }
}

int main()
{
    std::vector<int> vector;
    std::list<int> list;
    std::deque<int> deque;
    std::string str;

    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
        list.push_back(i);
        deque.push_back(i);
        str.push_back(i + '0');
    }

    tryFind(vector, 5, "vector");
    tryFind(list, 5, "list");
    tryFind(vector, 10, "vector");
    tryFind(list, 10, "list");
    tryFind(deque, 5, "deque");
    tryFind(deque, 10, "deque");
    
    /* 
    when we use easyfind with a std::string and a character,
    the character is implicitly converted to its ASCII value.
    This is because std::string::value_type is char,
    and char is an integral type in C++. When we call easyfind(str, '5'), 
    it's actually looking for the ASCII value of '5', which is 53. 
    */
    tryFind(str, '5', "string");
    tryFind(str, 'a', "string");

    return 0;
}