/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:17:35 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 19:04:05 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp" 

class ScavTrap: virtual public ClapTrap
{
	protected:
		int _energyPoints;
		bool _gate;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ClapTrap const &ref);
		
		ScavTrap &operator=(ScavTrap const &trap);

		void attack(std::string const & target);
		void guardGate();
};


#endif
