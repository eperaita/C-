/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:41:16 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 18:14:51 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSOurce default constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
		source[i] = NULL;
}

MateriaSource::~MateriaSource() 
{
	std::cout << "MateriaSource detructor called" << std::endl;
	//destroys learned materia, so, you dont need to delete in main what you have stored in MateriaSource
	int i = -1;
	while (source[++i])
		delete source[i];
}

MateriaSource::MateriaSource(MateriaSource const &ref)
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = ref;
}


MateriaSource &MateriaSource::operator=(MateriaSource const &ref)
{
	int i = -1;
    std::cout << "MateriaSource Assignation operator called" << std::endl;
    while (++i < 4)
    {
        if (ref.source[i])
            this->source[i] = ref.source[i]->clone();
        else
            this->source[i] = NULL;

    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *mat)
{
	int i = -1;
	while (source[i])
		i++;
	if (i < 4)
		source[i] = mat;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
  	int i = -1;
    
	while (++i < 4)
    {
        if (source[i] && !source[i]->getType().compare(type))
    		return (source[i]->clone());	
    }
	return 0;
}
