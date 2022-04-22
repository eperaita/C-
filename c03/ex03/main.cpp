/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:48:08 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 17:15:17 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap m("Marutchi");
		std::cout << "     _ _ _ " << std::endl;
    	std::cout << "   /       \\" << std::endl;
    	std::cout << "  |  ^ ~ ^  |" << std::endl;
    	std::cout << "   \\ _ _ _ / " << std::endl;
    	std::cout << std::endl;
	ScavTrap p("Puoperatchi");
		std::cout << "     <═╦═>" << std::endl;
    	std::cout << "     _ ║ _" << std::endl;
    	std::cout << "  /        \\" << std::endl;
    	std::cout << " |  ■       |" << std::endl;
    	std::cout << " |     o  ■ |" << std::endl;
    	std::cout << "  \\ _ _ _  /" << std::endl;
    	std::cout << std::endl;
	FragTrap n("Edgtchi");
		std::cout << "   ╔═════════╗ " << std::endl;
    	std::cout << "   ║         ║" << std::endl;
    	std::cout << "   ║     © © ║" << std::endl;
    	std::cout << "  ┌║     -   ║┐" << std::endl;
    	std::cout << "  ¨║         ║¨ " << std::endl;
    	std::cout << "   ╠════╦════╣" << std::endl;
    	std::cout << "   ╚════╬════╝" << std::endl;
    	std::cout << "        ■  " << std::endl;
    	std::cout << std::endl;
	DiamondTrap d("Diamond");
		std::cout << "      ░ ▒ ▒ ░ " << std::endl;
    	std::cout << "    ░ ▓ ▄ ▄ ▒ ░" << std::endl;
    	std::cout << "  ░ ▓ © ▒ ▓ ~ ▓ ░ "<< std::endl;
    	std::cout << "    ▒ ▒ ╔ ╗ ▒ ░   " << std::endl;
    	std::cout << "      ▒ ╚ ╝ ▒  " << std::endl;
    	std::cout << "        ▒ ▓  " << std::endl;
	std::cout << std::endl;
	std::cout << "     --- FIGHT!! ---" << std::endl;
	std::cout << std::endl;

	/*m.attack("Puoperatchi");
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
	p.guardGate();*/
	d.whoAmI();	
	d.attack("Marutchi");
	d.highFivesGuys();
	d.guardGate();
	d.takeDamage(p.get_damage());
		std::cout << d;
	d.beRepaired(10);
		std::cout << d;
	d.takeDamage(n.get_damage());
		std::cout << d;
	d.takeDamage(n.get_damage());
		std::cout << d;
	d.takeDamage(p.get_damage());
		std::cout << d;
	d.takeDamage(p.get_damage());
		std::cout << d;
	
	std::cout << std::endl;
	std::cout << "     --- TIMEOUT!! ---" << std::endl;
	std::cout << std::endl;

	return (0);
}
