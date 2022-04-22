/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:42 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 17:57:21 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

Data::Data()
{
    //std::cout << "Default constructor called" << std::endl;
}

Data::Data(float in): fl(in)
{
    //std::cout << "Parameter constructor called" << std::endl;
}
Data::Data(std::string in): str(in)
{
    //std::cout << "Parameter constructor called" << std::endl;
}
Data::Data(Data & ref) : str(ref.get_input())
{
    //std::cout << "Copy constructor called" << std::endl;
}
Data::~Data()
{
    //std::cout << "Destructor called" << std::endl;
}

std::string Data::get_input()
{
	return (this->str);
}
float  Data::get_float()
{
	return (this->fl);
}
