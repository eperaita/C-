/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:54:04 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:36:58 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

//The interface is an abstract class of pure methods. 
//Behaves like a template of functions, they are not defined but forces to the derived classes to defime them . 

class ICharacter
{
	    public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		//An extra method to print the inventory. So useful in main! Its not explicity prohibited but I don't know if it is allowed. Try it!
		//virtual void getInventory() = 0;
};


#endif
