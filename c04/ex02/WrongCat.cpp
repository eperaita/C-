/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 13:10:48 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
	type = "WrongCat";
     std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

WrongCat &WrongCat::operator=(WrongCat const &c)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = c.type;

    return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
    std::cout << "Mewwww" << std::endl;
}
