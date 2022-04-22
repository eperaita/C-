/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:23:40 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 19:07:32 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 300;
     std::cout << "Scav-Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) 
{
   	_hitPoints = 100;
	_energyPoints = 50;
   	_attackDamage = 20;
	_gate = false;
	std::cout << "Scavtrap born" << std::endl;
	std::cout << "          Hit Points: " << _hitPoints << std::endl;
	std::cout << "          Energy Points: " << _energyPoints << std::endl;
	std::cout << "          Attack Damage: " << _attackDamage << std::endl;
	
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap died" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap const &ref)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ref;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &trap) //  =
{
    //std::cout << "Assignation operator called" << std::endl;
    this-> _name = trap._name;
    this->_hitPoints =  trap._hitPoints; //vida
    this->_energyPoints = trap._energyPoints; //gasto por ataque
    this->_attackDamage = trap._attackDamage;

    return (*this);
}


void ScavTrap::attack(std::string const & target)
{
    std::cout <<  "-> ScavTrap " << _name << " strikes " << target << ", causing " << _attackDamage <<" points of damage!" << std::endl;

}

void ScavTrap::guardGate()
{
	_gate = true;
    std::cout << "-> ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}
