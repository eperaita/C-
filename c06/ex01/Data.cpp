/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:42 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 18:32:58 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

Data::Data()
{
    //std::cout << "Default constructor called" << std::endl;
}

Data::Data(float *in): input(reinterpret_cast<void *>(in))
{
    //std::cout << "Parameter constructor called" << std::endl;
}
Data::~Data()
{
    //std::cout << "Destructor called" << std::endl;
}


Data::Data(std::string *in): input(reinterpret_cast<void *>(in))
{
    //std::cout << "Parameter constructor called" << std::endl;
}

std::string *Data::get_str()
{
	return (reinterpret_cast<std::string *>(input));
}
float  *Data::get_float()
{
	return (reinterpret_cast<float *>(input));
}
