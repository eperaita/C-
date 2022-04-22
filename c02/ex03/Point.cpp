/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:55 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 17:25:24 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


Point::Point(void): _x(0), _y(0) {}


Point::~Point(void){}


Point::Point(Point const &point)
{
	*this = point;
}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Point &Point::operator=(Point const &point) //  =
{
    //std::cout << "Assignation operator called" << std::endl;
	*(Fixed*)&this->_x = point.getX();
	*(Fixed*)&this->_y = point.getY();
	return (*this);
}

///////////////////////////

float Point::getX(void) const
{
	return (_x.toFloat());
}
float Point::getY(void) const
{
	return (_y.toFloat());
}




///////////////////////////

