/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 13:00:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
     std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

Cat &Cat::operator=(Cat const &c)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = c.type;

    return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
    std::cout << "Mewwww" << std::endl;
}
