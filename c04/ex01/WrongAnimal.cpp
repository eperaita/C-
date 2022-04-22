/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 17:28:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
     std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &a)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = a.type;

    return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "..." << std::endl;
}
