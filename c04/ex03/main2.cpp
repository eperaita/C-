/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:54:34 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/04 18:22:52 by eperaita         ###   ########.fr       */
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
	std::cout << "-------------------------------         MAIN 2         ----------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" CLOSE << std::endl;
	
	std::cout << std::endl;
    std::cout << "--- NEW 2 CHARACTER CREATED ----" << std::endl << std::endl;
    ICharacter *ep = new Character("Eperaita");
    ICharacter *ak = new Character("Akuma");

	std::cout << std::endl;
    std::cout << "--- FILLING THE MATERIA SOURCE ----" << std::endl << std::endl;

    IMateriaSource *stock = new MateriaSource();
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();
    stock->learnMateria(ice);
    stock->learnMateria(cure);
	
	std::cout << std::endl;
    std::cout << "--- USING THE MATERIA SOURCE ----" << std::endl << std::endl;
    
	ep->equip(stock->createMateria("cure"));
	ep->equip(stock->createMateria("cure"));
	ep->equip(stock->createMateria("cure"));
	//ep->unequip(1);
	//ep->getInventory();
    ep->use(1, *ak);
	ak->equip(stock->createMateria("ice"));
	ak->equip(stock->createMateria("ice"));
	ak->equip(stock->createMateria("ice"));
	//ak->getInventory();
    ak->use(2, *ep);

    std::cout << std::endl;
    std::cout << "--- DELETING THE MATERIA SOURCE ----" << std::endl << std::endl;
	delete stock;

	std::cout << std::endl;
    std::cout << "--- DELETING THE CHARACTERS ----" << std::endl << std::endl;

    delete ep;
    std::cout << std::endl;
    delete ak;

	return (0);

}


