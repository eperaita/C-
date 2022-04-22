/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:29:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/21 12:12:52 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "fixed.hpp"


int const Fixed::_rawBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl; 
	_value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;

}

Fixed & Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits ( int const raw )
{
	this->_value = raw;
}
