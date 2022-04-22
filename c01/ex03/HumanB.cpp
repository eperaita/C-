/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:48:07 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/13 03:31:23 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
   	_name = name;
}

void HumanB::attack(void)//por que no es la misma para los dos human?
{
    std::cout << _name << " attacks with his " << w->getType() << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon *club)
{
	//std::cout << club.getType() << std::endl;
//	w->_type = club->getType();
	w = club;
};
