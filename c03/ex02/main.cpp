/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:48:08 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/02 18:37:24 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap m("Marutchi");
		std::cout << " ..._..." << std::endl;
    	std::cout << " |^ _ ^|" << std::endl;
    	std::cout << " ..._..." << std::endl;
    	std::cout << std::endl;
	ScavTrap p("Puoperatchi");
		std::cout << " ..._..." << std::endl;
    	std::cout << " |^ _ ^|" << std::endl;
    	std::cout << " ..._..." << std::endl;
    	std::cout << std::endl;
	FragTrap n("Nyorotchi");
		std::cout << " ..._..." << std::endl;
    	std::cout << " |^ _ ^|" << std::endl;
    	std::cout << " ..._..." << std::endl;
    	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "     --- FIGHT!! ---" << std::endl;
	std::cout << std::endl;

	
	m.attack("Puoperatchi");
	p.takeDamage(m.get_damage());
	std::cout << p;
	p.attack("Marutchi");
	m.takeDamage(p.get_damage());
	std::cout << m;
	n.highFivesGuys();
	m.beRepaired(10);
	std::cout << m;
	p.beRepaired(1);
	std::cout << p;
	p.guardGate();
	
	std::cout << std::endl;
	std::cout << "     --- TIMEOUT!! ---" << std::endl;
	std::cout << std::endl;

	return (0);
}
