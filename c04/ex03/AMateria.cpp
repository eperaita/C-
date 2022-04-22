/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 15:34:04 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
     std::cout << "Materia default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
     std::cout << "Materia parameter constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Materia destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &ref)
{
    std::cout << "Materia Copy constructor called" << std::endl;
    *this = ref;
}

AMateria &AMateria::operator=(AMateria const &a)
{
    std::cout << "Materia Assignation operator called" << std::endl;
    this-> type = a.type;
	//While assigning a Materia to another, copying the type doesn’t make sense...
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::setType(std::string t)
{
	this->type = t;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "*An unknown materia has been exploit by " << target.getName() << "*" << std::endl;
}
