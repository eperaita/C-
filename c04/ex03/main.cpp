/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:22:40 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/04 18:22:51 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#define CLOSE "\001\033[0m\002"
#define BOLD "\001\033[1m\002"

int main()
{	
	std::cout << BOLD"-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------         MAIN 1         ----------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" CLOSE << std::endl;

	std::cout << std::endl;
	std::cout << "----CREATE 2 MATERIA: Ice and Cure-----" << std::endl << std::endl;
	
	AMateria *i = new Ice();
	AMateria *c = new Cure();
	//AMateria *m = new AMateria(); //abstract class cannot be instantiated

	std::cout << std::endl;
	std::cout << "----CHECK MATERIA'S ATTRIBUTES-----" << std::endl << std::endl;
	
	std::cout << "Ice: " << i->getType() << std::endl;
	std::cout << "Cure: " << c->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "--- CLONE ICE AND CURE and CHECK----" << std::endl << std::endl;
	AMateria *ci = i->clone();
	AMateria *cc = c->clone();
	AMateria *ccc = c->clone();
	std::cout << "Ice: " << ci->getType() << std::endl;
	std::cout << "Cure: " << cc->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "--- NEW CHARACTER CREATED, EQUIPED AND UNEQUIPED ----" << std::endl << std::endl;
	ICharacter *ep = new Character("Eperaita");
	
	//ep->getInventory();
	
	std::cout << std::endl;
	std::cout << "--- EQUIP AND UNEQUIP ----" << std::endl << std::endl;
	
	ep->equip(i);
	ep->equip(c);
	ep->equip(cc);
	ep->equip(ci);
	ep->equip(ci);
	ep->equip(cc);
	ep->unequip(1);
	ep->equip(ccc);

	std::cout << std::endl;
	std::cout << "--- NEW CHARACTER TO INTERACT ----" << std::endl << std::endl;
	
	AMateria *ni = new Ice();
	AMateria *nc = new Cure();

	Character ak("Akuma");
	ak.equip(ni);
	ak.equip(nc);
	
	std::cout << std::endl;
	std::cout << "--- CLONE NEW CHARACTER (to check deep copy of Character) ----" << std::endl << std::endl;

	ICharacter *clone = new Character(ak);
	std::cout << std::endl;
	AMateria *nni = new Ice();
	AMateria *nnc = new Cure();
	ak.equip(nni);
	ak.unequip(1);
	ak.equip(nnc);
	//clone->getInventory();


	std::cout << std::endl;
	std::cout << "--- USING CHARACTER SKILLS WITH MATERIALS ----" << std::endl << std::endl;
	ep->use(1, *clone);
	ep->use(0, *clone);
	ep->use(4, *clone); //out of the inventory
	clone->use(0, *ep);
	
	std::cout << std::endl;
	std::cout << "--- DELETING THE CHARACTERS ----" << std::endl << std::endl;
	
	delete ep;
	std::cout << std::endl;
	delete clone;
	std::cout << std::endl;

	return (0);
}

///EACH MATERIAL IS UNIQUE! Need to equip each [] of the invemntory with a new one or clone(), or will be freed twice and SEGFAULT
