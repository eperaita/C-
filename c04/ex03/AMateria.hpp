/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:54:33 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 15:34:01 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(); 		
		AMateria(std::string const & type);
		virtual ~AMateria();   
		AMateria(AMateria const &ref);

		AMateria &operator=(AMateria const &a);
		
		std::string const & getType() const; //Returns the materia type
		void setType(std::string t) ; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target); 
};

//#include "Character.hpp" //not necessary, its included in the cpp. 


#endif
