/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:13:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 17:26:22 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie z;
	Zombie *p;
	
	p = z.newZombie("*Heap");
	p->announce();// si announcement puede ser publica la llamo, porque si devuelve puntero "para usar otra vez en el codigo"
	z.randomChump("Stack");
	delete p;
	return(0);
}
