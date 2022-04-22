/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:28:25 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/04 20:07:20 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &n)
{
	int i = -1;
    std::cout << "Character constructor called" << std::endl;
	
	name = n;
	while (++i < 4)
		inventory[i] = NULL;
    std::cout << "      Name: " << name << std::endl;
	i = -1;
	while (++i < 100)
		trash[i] = NULL;
}

Character::~Character()
{
	int i = -1;
	
    std::cout << name << " Character destructor called" << std::endl;
	while (++i < 4)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
    std::cout << "     >Inventory deleted" << std::endl;

	i = -1;
		while (++i < 100)
		{
			if (trash[i] != NULL)
				delete trash[i];
		}
    std::cout << "     >Trash deleted" << std::endl;
}

Character::Character(Character const &ref)
{
    std::cout << "Character Copy constructor called" << std::endl;
    *this = ref;
}

Character &Character::operator=(Character const &ref)
{
	int i = -1;
    std::cout << "Character Assignation operator called" << std::endl;
	this->name = ref.name;
    while (++i < 4)
    {
        if (ref.inventory[i] && !ref.inventory[i]->getType().compare("ice"))
		{
            this->inventory[i] = ref.inventory[i]->clone();
    		std::cout << "Cloned ice to inventory" << std::endl;

		}
		else if (ref.inventory[i] && !ref.inventory[i]->getType().compare("cure"))
		{
            this->inventory[i] = ref.inventory[i]->clone();
    		std::cout << "Cloned cure to inventory" << std::endl;
		}
		else
            this->inventory[i] = NULL;

    }
    i = -1;
    while (++i < 100)
        this->trash[i] = NULL;
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	while (inventory[i] && i < 4)
	{
		i++;
	}
	if (i != 4)
	{
		inventory[i] = m;
    	std::cout << getName() << "'s inventory n*" << i << " filled with " << m->getType() << std::endl;

	}
}
	
void Character::unequip(int idx)
{
	//When unequip, must not delete the materia, but can't lost the reference to it, because in the destructor must delete it. 
	//A new inventory named trash. 
	
	int i = -1;
	while(trash[++i] != NULL)
		continue;
	trash[i] = inventory[idx];
	inventory[idx] = NULL;

	std::cout << getName() << "'s inventory n*" << idx << " emptied."  << std::endl;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 4)
		inventory[idx]->use(target);
}

//An extra method inherited. To print the inventory.Not explicity prohibited but I don't know if it is allowed. Try it!
/*void Character::getInventory()
{
	int i = -1;

    while (++i < 4)
	{
		if (inventory[i] != NULL)
			std::cout << getName() << "'s inventory n*" << i << " is filled with " << inventory[i]->getType()  << std::endl;
		else 
			std::cout << getName() << "'s inventory n*" << i << " is empty. " << std::endl;
	}
}*/

