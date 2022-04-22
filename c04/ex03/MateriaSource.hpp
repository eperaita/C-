/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:40:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 17:49:15 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria *source[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &ref);
		MateriaSource &operator=(MateriaSource const &ref);
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const & type);

};

#endif
