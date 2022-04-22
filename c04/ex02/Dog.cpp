/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:41:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:01:15 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
	b = new Brain(Brain());
     std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete b;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
	b = new Brain(*ref.b);
}

Dog &Dog::operator=(Dog const &d)
{
    std::cout << "Assignation operator called" << std::endl;
    this-> type = d.type;
	delete b;
	b = new Brain(*d.b);
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

std::string Dog::getBrain(int i) const
{
    return (this->b->getIdea(i));

}
void Dog::setBrain(int i, std::string idea)
{
	return (this->b->setIdea(i, idea));
}
