/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:23:40 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 19:04:36 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap() , FragTrap() 
{
	ClapTrap::_name = "Unknown_clap_name";
     std::cout << "Diamond-Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name) , FragTrap(name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "Diamond-Parameter constructor called!" << std::endl;
	std::cout << "          Hit Points: " << _hitPoints << std::endl;
    std::cout << "          Energy Points: " << _energyPoints << std::endl;
    std::cout << "          Attack Damage: " << _attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond-Destructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(ClapTrap const &ref)
{
    std::cout << "Diamond-Copy constructor called" << std::endl;
    *this = ref;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &trap)
{
    std::cout << "Diamond-Assignation operator called" << std::endl;
    this-> _name = trap._name;
    this->_hitPoints =  trap._hitPoints; 
	this->_energyPoints = trap._energyPoints; 
	this->_attackDamage = trap._attackDamage;

    return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "-> My Diamond name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
	
}

//a ver, Fragtrap ha sobreescrito a Scavtrap!!! Hay ambiguedad en las herencias de variables.  ->  using
//  Claptrap::_name// simepre que llae a funciones de sus ancestros se llamara name_clap_name, solo dse puede llamar name desde sus propias funciones. No tiene sentido porque le mandas name al constructor del abuelo para que le de nombre al nieto , pero luegola funcion que accede a la variable _name accede a su propio _name.

