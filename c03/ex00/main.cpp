/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:48:08 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 17:25:35 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap m("Marutchi");

	m.attack("Puoperatchi");
	m.takeDamage(300);
	std::cout << m;
	m.beRepaired(4);
	std::cout << m;

	return 0;
}
