/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:55:17 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:01:47 by eperaita         ###   ########.fr       */
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
	//Brain´s copy constructor copies the whole ideas 
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = ref; //calls assignation operator and:
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
