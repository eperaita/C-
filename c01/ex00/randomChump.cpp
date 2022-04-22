/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:38:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 17:27:32 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie z;//no haria falta crear otro objeto, viene dado y accedo con el puntero this, pero el subject lo especifica

    z.z_name = name;
    z.announce();
}
