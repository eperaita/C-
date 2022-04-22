/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:21:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:21:33 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "Int.hpp"
#include <cstring>


Int::Int(std::string &str)
{
	_str = str;
	//std::cout << "Constructor called" << std::endl;
}

Int::~Int()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////// INHERITED GETTERS REDEFINED TO CONVERT DATA ////////////

void Int::get_char()
{
	char c = static_cast<char>(atoi(_str.c_str()));
	if (c < 32 || c > 126)
		std::cout << "char : Non displayable" << std::endl; 
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void Int::get_int()
{
	std::cout << "int: " << atoi(_str.c_str()) << std::endl;
}

void Int::get_float()
{
	std::cout <<  std::fixed << std::setprecision(1); 
	std::cout << "float: " << static_cast<float>(atoi(_str.c_str()))  << "f" << std::endl;//ñap
}

void Int::get_double()
{
	std::cout <<  std::fixed << std::setprecision(1); 
	std::cout << "double: " << static_cast<double>(atoi(_str.c_str())) << std::endl;
}

