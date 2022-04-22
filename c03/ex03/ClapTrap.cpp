/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:05:45 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 17:29:18 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

///////// CONSTRUCTORS,  DESTRUCTORS AND OPERATORS ////////////////

ClapTrap::ClapTrap(): _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	 std::cout << "Clap-Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	 std::cout << "Clap-Parameter constructor called" << std::endl;
	std::cout << "          Hit Points: " << _hitPoints << std::endl;
	std::cout << "          Energy Points: " << _energyPoints << std::endl;
	std::cout << "          Attack Damage: " << _attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap-Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref)
{
    std::cout << "Clap-Copy constructor called" << std::endl;
	*this = ref;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &trap) 
{
    std::cout << "Clap-Assignation operator called" << std::endl;
    this-> _name = trap._name;
    this->_hitPoints =  trap._hitPoints;
    this->_energyPoints = trap._energyPoints; 
	this->_attackDamage = trap._attackDamage;

    return (*this);
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &trap)
{
	out << "          Hit Points: " << trap.get_hp() << std::endl;
    out << "          Energy Points: " << trap.get_ep() << std::endl;
	return (out);
}



//////////////GET VARS//////////////////


unsigned int ClapTrap::get_hp() const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::get_ep() const
{
    return (this->_energyPoints);
}

int ClapTrap::get_damage() const
{
    return (this->_attackDamage);
}

//////////////////////////////////////////

void ClapTrap::attack(std::string const & target)
{
	std::cout <<  "-> ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage <<" points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout <<  "-> ClapTrap " << _name << " has received " << amount << " points of damage!" << std::endl;
    if (get_hp() < amount)
    {
        _hitPoints = 0;
        std::cout <<  "-> ClapTrap " << _name << " has died!" << std::endl;
    }
    else
        _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (get_ep() < amount)
        std::cout <<  "-> ClapTrap " << _name << " cannot repair! Not enough points of energy!" << std::endl;
    else
    {
        _energyPoints -= amount;
        _hitPoints += amount;
        std::cout <<  "-> ClapTrap " << _name << " has repaired " << amount << " points of HP!" << std::endl;
    }
};
