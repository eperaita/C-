/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:19:01 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 12:17:27 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
    type = "cure";
     std::cout << "Cure default constructor called" << std::endl;
}

/*Cure::Cure(Cure const &ty) //no parameter constructor
{
    this->type = "cure";
     std::cout << "Cure default constructor called" << std::endl;
}*/

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &ref)
{
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = ref;
}

Cure &Cure::operator=(Cure const &a)
{
    std::cout << "Cure Assignation operator called" << std::endl;
    this-> type = a.type;

    return (*this);
}

///////////// REDEFINITION OF INHERITED METHODS ////////////////
AMateria *Cure::clone() const
{
	AMateria *clone = new Cure();
	clone->setType(this->getType());
    return (clone);
}


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;

}
