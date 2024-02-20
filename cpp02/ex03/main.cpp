/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:41:37 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/13 14:40:09 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.cpp"

int main(void)
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(0), Fixed(2));
    Point c(Fixed(2), Fixed(0));

    Point testPoints[] = {
        Point(Fixed(1), Fixed(1)),
        Point(Fixed(0), Fixed(0)),        // Vertex A
        Point(Fixed(0), Fixed(1)),        // On the edge AB
        Point(Fixed(1), Fixed(0)),        // On the edge AC
        Point(Fixed(0.5f), Fixed(0.75f)), // Inside the triangle
        Point(Fixed(1.1f), Fixed(1.1f))   // Outside the triangle
    };

    const char *testNames[] = {
        "Test Case 1:\n",
        "Test Case 2:\n",
        "Test Case 3:\n",
        "Test Case 4:\n",
        "Test Case 5:\n",
        "Test Case 6:\n"};

    size_t numTestCases = sizeof(testPoints) / sizeof(testPoints[0]);

    for (size_t i = 0; i < numTestCases; ++i)
    {
        std::cout << testNames[i];
        if (bsp(a, b, c, testPoints[i]))
            std::cout << "The point is inside the triangle\n" << std::endl;
        else
            std::cout << "The point is outside the triangle\n" << std::endl;
    }
    return 0;
}
