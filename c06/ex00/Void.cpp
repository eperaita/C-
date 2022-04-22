/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:48 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:10:17 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Void.hpp"
#include <cstring>

Void::Void()
{
	//std::cout << "Default constructor called" << std::endl;
}

Void::Void(std::string &str): _str(str)
{
	//std::cout << "Constructor called" << std::endl;
}

Void::~Void()
{
	//std::cout << "Destructor called" << std::endl;

}


