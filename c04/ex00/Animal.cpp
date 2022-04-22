/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 13:01:55 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
	type = "_";
     std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

Animal &Animal::operator=(Animal const &a)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = a.type;

    return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "..." << std::endl;
}
