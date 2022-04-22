/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:09:32 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 12:16:48 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		//Ice(std::string const & type); //no parameter constructor
		~Ice();
		Ice(Ice const &ref);

		Ice &operator=(Ice const &a);
		
		//Virtual method (from AMateria) forces to redefine the methods by the child classes.
		AMateria* clone() const;  
		void use(ICharacter& target);
};

#endif
