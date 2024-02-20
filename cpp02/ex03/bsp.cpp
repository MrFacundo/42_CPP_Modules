/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:24:12 by ftroiter          #+#    #+#             */
/*   Updated: 2024/02/13 14:38:17 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
    return (p1.getX() * (p2.getY() - p3.getY()) +
            p2.getX() * (p3.getY() - p1.getY()) +
            p3.getX() * (p1.getY() - p2.getY())) /
           2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate areas of sub-triangles
    Fixed areaABC = calculateArea(a, b, c);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);
    Fixed areaPAB = calculateArea(point, a, b);

    // Calculate barycentric coordinates
    Fixed alpha = areaPBC / areaABC;
    std::cout << "Alpha: " << alpha << std::endl;
    Fixed beta = areaPCA / areaABC;
    std::cout << "Beta: " << beta << std::endl;
    Fixed gamma = areaPAB / areaABC;
    std::cout << "Gamma: " << gamma << std::endl;

    if (alpha >= 0 && beta >= 0 && gamma >= 0)
        return true;
    return false;
}
