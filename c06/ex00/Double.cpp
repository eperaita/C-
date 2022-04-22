/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:21:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 17:08:40 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "Double.hpp"
#include <cstring>

Double::Double(std::string &str)
{
	_str = str;
	//std::cout << "Constructor called" << std::endl;
}

Double::~Double()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////// INHERITED GETTERS REDEFINED TO CONVERT DATA ////////////

void Double::get_char()
{
	int c = std::stoi(_str.c_str());
	if (c < 32 || c > 126)
		std::cout << "char : Non displayable" << std::endl; 
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}

void Double::get_int()
{
	std::cout << "int: " << static_cast<int>(std::stof(_str.c_str())) << std::endl;
}

void Double::get_float()
{
	size_t prec = _str.size() - _str.find(".", 0);
	std::cout <<  std::fixed << std::setprecision(prec - 1); 
	std::cout << "float: " << static_cast<float>(std::stof(_str.c_str())) << "f"<< std::endl;//ñap
}

void Double::get_double()
{
	size_t prec = _str.size() - _str.find(".", 0);
	std::cout <<  std::fixed << std::setprecision(prec - 1); 
	std::cout << "double: " << static_cast<double>(std::stof(_str.c_str())) << std::endl;
}

