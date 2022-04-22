/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:17:35 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 19:07:59 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp" 
#include "FragTrap.hpp" 

class DiamondTrap: public ScavTrap, public FragTrap
{
	protected:
		std::string _name;
		using ScavTrap::_energyPoints; 	


	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(ClapTrap const &ref);
		
		DiamondTrap &operator=(DiamondTrap const &trap);
		
		using ScavTrap::attack;
		void whoAmI();
};

		//HEREDADAS//
//ClapTrap::_name;
//Estas no hacen falta declararlas con using, porque ya las sobreescribe el segundo, si hubiera un tercero si seria necesario especificar queheredan del segundo
	//using FragTrap::_hitPoints;
	//using FragTrap::_attackDamage; 

/*void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);*/

/*void highFivesGuys(void);
void attack(std::string const & target);
void guardGate();*/



#endif
