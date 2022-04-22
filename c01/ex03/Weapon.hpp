/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:00:15 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/15 18:26:59 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		const std::string &getType(void); //devuelve &_type
		void setType(std::string type);

	private:
		std::string _type;
};

#endif
