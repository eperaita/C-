/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:45:17 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/17 20:33:29 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	int i = -1;
	Zombie *z;

	z = new Zombie [N];
	while(++i < N)
	{
		z[i].z_name = name;
		z[i].announce();
	}
	return (&z[0]);

	/* VERSION CON ARRAY EN LA CLASE
	  this->horde = new Zombie *[N];//array de punteros? std::vector?
    while(++i < N)
    {
        this->horde[i] = newZombie(name);
        this->horde[i]->announce();
    }
    return (this->horde[0]);//porque devulevo el puntero al primero?
	 */

}
