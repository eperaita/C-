/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:24 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 17:22:59 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>
#include <iostream>

float get_area(Point const a, Point const b, Point const c)
{
    //AREA = [ x1(y2 - y3) + x2(y3 - y1) + x3(y1-y2)] / 2
    return (fabs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area(get_area(a, b, c));
    Fixed PAB(get_area(point, a, b));
    Fixed PBC(get_area(point, b, c));
    Fixed PAC(get_area(point, a, c));

    if (PAB == 0 || PBC == 0 || PAC == 0)
    {
        std::cout << "You are in BORDERLINE!" <<  std::endl;
        return (false);
    }
    else if (PAB + PBC + PAC == area)
    {
        std::cout << "You are IN!" <<  std::endl;
        return (true);
    }
    else
    {
        std::cout << "You are OUT!" <<  std::endl;
        return (false);
    }
}
