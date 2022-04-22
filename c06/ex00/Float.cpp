/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:21:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:21:30 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "Float.hpp"
#include <cstring>


Float::Float(std::string &str)
{
	_str = str;
	//std::cout << "Constructor called" << std::endl;
}

Float::~Float()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////// INHERITED GETTERS REDEFINED TO CONVERT DATA ////////////

void Float::get_char()
{
	int c = std::stoi(_str.c_str());
	if (c < 32 || c > 126)
		std::cout << "char : Non displayable" << std::endl; 
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}

void Float::get_int()
{
	std::cout << "int: " << static_cast<int>((std::stof(_str.c_str()))) << std::endl;
}

void Float::get_float()
{
	size_t prec = _str.size() - _str.find(".", 0) - 1;//resta uno mas por la f
	std::cout <<  std::fixed << std::setprecision(prec - 1); 
	std::cout << "float: " << static_cast<float>(std::stof(_str.c_str())) << "f"<< std::endl; //ñap
}

void Float::get_double()
{
	size_t prec = _str.size() - _str.find(".", 0) - 1;//resta uno mas por la f
	std::cout <<  std::fixed << std::setprecision(prec - 1); 
	std::cout << "double: " << static_cast<double>(std::stof(_str.c_str())) << std::endl;
}

