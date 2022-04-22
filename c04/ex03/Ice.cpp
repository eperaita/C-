/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 12:18:04 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
    type = "ice";
     std::cout << "Ice default constructor called" << std::endl;
}

/*Ice::Ice(Ice const &ty) //no parameter constructor
{
    type = "ice";
     std::cout << "Ice parameter constructor called" << std::endl;
}*/

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &ref)
{
    std::cout << "Ice Copy constructor called" << std::endl;
    *this = ref;
}

Ice &Ice::operator=(Ice const &a)
{
    std::cout << "Ice Assignation operator called" << std::endl;
    this-> type = a.type;

    return (*this);
}

////////////// REDEFINITION OF INHERITED METHODS////////////////

AMateria *Ice::clone() const
{
	AMateria *clone = new Ice();
	clone->setType(this->getType());
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
