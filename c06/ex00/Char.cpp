/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:21:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:09:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "Char.hpp"
#include <cstring>


Char::Char(std::string &str)//: _str(str)
{
	_str = str;
	//std::cout << "Constructor called" << std::endl;
}

Char::~Char()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////// INHERITED GETTERS REDEFINED TO CONVERT DATA ////////////

void Char::get_char()
{
	std::cout << "char: '" << _str[0] << "'" << std::endl;
}

void Char::get_int()
{
	std::cout << "int: " << static_cast<int>(_str[0]) << std::endl;
}

void Char::get_float()
{
	std::cout <<  std::fixed << std::setprecision(1); 
	std::cout << "float: " << static_cast<float>(_str[0]) << "f" << std::endl; //ñap
}

void Char::get_double()
{
	std::cout <<  std::fixed << std::setprecision(1); 
	std::cout << "double: " << static_cast<double>(_str[0]) << std::endl;
}
