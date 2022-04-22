/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:23:40 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 19:00:13 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
     std::cout << "Frag-Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) 
{
   	_hitPoints = 100;
	_energyPoints = 100;
   	_attackDamage = 30;
	std::cout << "Frag-Parameter constructor called" << " --> ";
	std::cout << _name << " is in!" << std::endl;
	std::cout << "          Hit Points: " << _hitPoints << std::endl;
    std::cout << "          Energy Points: " << _energyPoints << std::endl;
    std::cout << "          Attack Damage: " << _attackDamage << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Frag-Destructor called" << std::endl;
}

FragTrap::FragTrap(ClapTrap const &ref)
{
    std::cout << "Frag-Copy constructor called" << std::endl;
    *this = ref;
}

FragTrap &FragTrap::operator=(FragTrap const &trap) //  =
{
    std::cout << "Frag-Assignation operator called" << std::endl;
    this-> _name = trap._name;
    this->_hitPoints =  trap._hitPoints; //vida
    this->_energyPoints = trap._energyPoints; //gasto por ataque
    this->_attackDamage = trap._attackDamage;

    return (*this);
}


void FragTrap::highFivesGuys()
{
	std::cout <<  "-> FragTrap " << _name << " says: -Hey! High fives!" << std::endl;
}
