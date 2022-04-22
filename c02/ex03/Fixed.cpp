/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:29:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 12:44:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

////NOTA: VOLVER A HABLILITAR OS PRINT DE LLAMADA


int const Fixed::_bits = 8;

Fixed::Fixed(void) //contructor por defecto
{
	//std::cout << "Default constructor called" << std::endl; 
	_fixed_point_value = 0;
}

/////////////DESTRUCTOR////////

Fixed::~Fixed(void) 
{
	//std::cout << "Destructor called" << std::endl;

}

///////////////COPIA//////////

Fixed::Fixed(Fixed const &fixed) 
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;

}

////////////SET Y GET /////////

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point_value);
}

void Fixed::setRawBits ( int const raw )
{
    this->_fixed_point_value = raw;
}


/////////////INT TO FIXED////////input *  2^8 bits

Fixed::Fixed(int const input) //constructor para int
{
    //std::cout << "Integer constructor called" << std::endl;
	setRawBits( input * (1<< _bits));
    //std::cout << "fixed set:" << _fixed_point_value << std::endl;
	
}

///////////FLOAT TO FIXED//////// input *  2^8 bits

Fixed::Fixed(float const input) //constructor para float 
{
    //std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(input * (1<< _bits))) ;

	//por que hay que redondear a la entrada tambien?, si puedo almacenar el numero exacto en fixed!!!!
}


///FIXED TO INT //input /  2^8 bits

int Fixed::toInt( void ) const
{
    return(_fixed_point_value / (1<< _bits));
}

///FIXED TO FLOAT //input /  2^8 bits

float Fixed::toFloat( void ) const
{
    return ( roundf(getRawBits()) / (1 << _bits));
}

///////////////////////////////////////////////////////////////////
///////////////////////////OPERATORS///////////////////////////////
///////////////////////////////////////////////////////////////////

//Los operadores son llamados desde el objeto que encuentran justo delante, por lo que llevan implcito un parametro mas, de tipo Fixed. (el error que da has 3 parameters a veces alude a eso, llevaria 2, mas 1 que es el propio objeto.)

///////////////////////////Comparación//////////////////////////////////

Fixed &Fixed::operator=(Fixed const &fixed) //  =
{
	//std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

bool Fixed::operator<(Fixed const &fixed) const // <
{
    //std::cout << "< called" << std::endl;
   	if (this->getRawBits() < fixed.getRawBits())
		return (true);
    return (false);
}

bool Fixed::operator>(Fixed const &fixed) const // >
{
    //std::cout << "> called" << std::endl;
    if (this->getRawBits() > fixed.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(Fixed const &fixed) const // <=
{
    //std::cout << "<= called" << std::endl;
    if (this->getRawBits() <= fixed.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(Fixed const &fixed) const // >=
{
    //std::cout << ">= called" << std::endl;
    if (this->getRawBits() >= fixed.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(Fixed const &fixed) const // !=
{
    //std::cout << "!= called" << std::endl;
    if (this->getRawBits() != fixed.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(Fixed const &fixed) const // ==
{
    //std::cout << "== called" << std::endl;
    if (this->getRawBits() == fixed.getRawBits())
        return (true);
    return (false);
}

///////////////////////////Suma, resta, multiplicación y división//////////////////////////////////

Fixed Fixed::operator+(Fixed const &fixed) const 
{
    //std::cout << "+ operator called" << std::endl;
	Fixed temp;
	temp.setRawBits(getRawBits() + fixed.getRawBits());
    return (temp);
    //return (Fixed(getRawBits() + fixed.getRawBits()));
	////por que no me deja hacerlo todo de una con el constructor, por el round??
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
    //std::cout << "- operator called" << std::endl;
	Fixed temp;
    temp.setRawBits(getRawBits() - fixed.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(Fixed const &fixed) const //OVERFLOAT
{
    std::cout << "* operator called" << std::endl;

	Fixed temp;
	temp.setRawBits((this->getRawBits() * fixed.getRawBits()) / (1<< _bits));


    return (temp);
}

Fixed Fixed::operator/(Fixed const &fixed) const  ///UNDERFLOAT
{
    std::cout << "/ operator called" << std::endl;

	Fixed temp;
	temp.setRawBits((roundf(this->getRawBits()) / fixed.getRawBits()) * (1<< _bits));
    return (temp);
}

//////////////////////////Pre/post incremento/decremento//////////////////////////////////

//los operadores de post incremento son tipo void porque incrementan despues de devolver el valor, por lo que hacen una copia con el contructor copia y luego lo suman, devolviendo la copia(tipo Fixed). Sin embargo los de pre incremento suman y luego devuelven la referencia(&Fixed).

Fixed Fixed::operator++(int)       //i++
{
	Fixed copy(*this);
	this->_fixed_point_value++;
	return (copy);
}

//por que tiene que ser el parametro un int sin declarar?? no lo uso ni hago alusion. 
//yo queria un parametro de tipo fixed, porque al final es lo que se va a encontrar detras, a diferencia del i++ que ya viene llamado de su propio objeto. 
//el int es para diferenciar los operadores i++ e ++i, solo sintaxis de polimorfismo. por eso no declarar el int
Fixed &Fixed::operator++(void) 		//++i
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator--(int)        //i--
{
	Fixed copy(*this);
	this->_fixed_point_value--;
	return (copy);
}

Fixed &Fixed::operator--(void)  		//--i
{
	this->_fixed_point_value--;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) // operador <<
{
	out << fixed.toFloat();
	return (out);
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	else 
		return (fixed2);
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	else 
		return (fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}
