/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 13:00:23 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
     std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

Dog &Dog::operator=(Dog const &d)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = d.type;

    return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
    std::cout << "Woof, woof" << std::endl;
}
