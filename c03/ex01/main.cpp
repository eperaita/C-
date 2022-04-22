/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:48:08 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 16:58:57 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap m("Marutchi");
	ScavTrap p("Puoperatchi");

	std::cout << std::endl;
	m.attack("Puoperatchi");
	p.takeDamage(0);
	std::cout << p;
	p.attack("Marutchi");
	m.takeDamage(20);
	std::cout << m;
	m.beRepaired(10);
	std::cout << m;
	p.beRepaired(1);
	std::cout << p;
	p.guardGate();
	std::cout << std::endl;

	return (0);
}
