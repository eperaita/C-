/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:55:17 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 18:52:35 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int i = 100;

	while (i--)
		ideas[i] = "This is my idea n*" + std::to_string(i);
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &ref)
{
	//constructor de copia de Brain se encarga de copiar todo el array de ideas
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = ref; //llama al operador de asignacion
}

Brain &Brain::operator=(Brain const &ref)
{
	int i = -1;
    std::cout << "Brain Assignation operator called" << std::endl;
	while (++i < 100)
    {
        this->setIdea(i, ref.getIdea(i));
    }
    return (*this);
}

std::string Brain::getIdea(int i) const
{
    return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}
