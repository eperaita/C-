/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Special.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:21:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:09:14 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "Special.hpp"
#include <cstring>


Special::Special(std::string &str)
{
	_str = str;
	//std::cout << "Constructor called" << std::endl;
	if ( (_str.compare("+inff") || _str.compare("-inff") || _str.compare("nanf")) && _str.size() > 4)
	{
		print[0] ="Non displayable";
		print[2] = _str;
		print[1] = _str.erase(_str.size() -1, 1);
		print[3] = _str;
	}
	else
	{
		print[0] ="impossible";
		print[1] = "impossible";
		print[3] = _str;
		print[2] = _str.append("f");;
	}
}

Special::~Special()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////// INHERITED GETTERS REDEFINED TO CONVERT DATA ////////////

void Special::get_char()
{
	std::cout << "char: " << print[0] << std::endl;
}

void Special::get_int()
{
	std::cout << "int: " << print[1] << std::endl;
}

void Special::get_float()
{
	std::cout << "float :" << print[2] << std::endl;
}

void Special::get_double()
{
	std::cout << "double: " << print[3] << std::endl;
}

