/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:01:26 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
	b = new Brain(Brain());
    std::cout << "Cat default constructor called" << std::endl;
}
	//b = new Brain();//podia alojar en el *p un nuevo brain y luego copiarlo a mano
	//Utilizo el constructor de copia de Brain para que este aloje una nueva memoria para el array y se la asigne. OK??

Cat::~Cat()
{
	delete b;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &ref)
{
    std::cout << "Cat Copy constructor called" << std::endl;
	*this = ref;
	b = new Brain(*ref.b);
}
	//declarar un nuevo brain y copiar en el asigantion operator todas las strings, o directamente utilizar el copy constructor de brain OK ?
	//	Ademas, el copy constructor de Brain copia el array de ideas. 

Cat &Cat::operator=(Cat const &c)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    this-> type = c.type;
	delete b;
	b = new Brain(*c.b);
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

std::string Cat::getBrain(int i) const
{
	return (this->b->getIdea(i));

}
void Cat::setBrain(int i, std::string idea)
{
	return (this->b->setIdea(i, idea));

}
