/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:04:28 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 17:49:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria *mat) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
