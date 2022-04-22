/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:29:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/22 11:32:56 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed(void) //contructor por defecto
{
	std::cout << "Default constructor called" << std::endl; 
	_fixed_point_value = 0;
}

///INT TO FIXED //input *  2^8 bits

Fixed::Fixed(int const input) //constructor para int
{
    std::cout << "Integer constructor called" << std::endl;
	setRawBits( input * (1<< _bits));
    //std::cout << "fixed set:" << _fixed_point_value << std::endl;
	
}

///FLOAT TO FIXED  // input *  2^8 bits

Fixed::Fixed(float const input) //constructor para float 
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(input * (1<< _bits))) ;

	//por que hay que redondear a la entrada tambien?, si puedo almacenar el numero exacto en fixed!!!!
}

Fixed::~Fixed(void) //destructor
{
	std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(Fixed const &fixed) // copia 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;

}

Fixed &Fixed::operator=(Fixed const &fixed) //operador =
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) // operador <<
{
	out << fixed.toFloat();
	return (out);
}


int Fixed::getRawBits( void ) const //get
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void Fixed::setRawBits ( int const raw ) //set 
{
	this->_fixed_point_value = raw;
}

///FIXED TO INT //input /  2^8 bits

int Fixed::toInt( void ) const //fixed to int
{
	return(_fixed_point_value / (1<< _bits));
}

///FIXED TO FLOAT //input /  2^8 bits

float Fixed::toFloat( void ) const //fixed to float 
{
	return ( roundf(getRawBits()) / (1 << _bits));

	//////casteo guarro, no es necesario ya que estamos haciendo un asteo limpio
	//return ( (float)getRawBits() / (float)(1<< _bits)) ;
}


