/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:28:14 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 15:38:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character:  public ICharacter
{
	private:
		AMateria *inventory[4];
		AMateria *trash[100];
		std::string name;
	public:
		Character();
		Character(std::string const &n);
		~Character();
		Character(Character const &ref);

		Character &operator=(Character const &a);
	
		
		//This functions are inherited from the Interface, but must redefine them. And redeclare them!
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
		//An extra method inherited. To print the inventory.Not explicity prohibited but I don't know if it is allowed. Try it!
		//void getInventory();
};

#endif
