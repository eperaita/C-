/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Special.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:00:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 19:22:05 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPECIAL_HPP
#define SPECIAL_HPP

#include "Void.hpp"

class Special : virtual public Void
{
	private:
		std::string print[4];
		//un array que para cada caso es un array de strings?? o un if en cada y que saque directamente _str?? mejor!

	public:
		Special(std::string &str);
		~Special();
		
		void get_char();
		void get_int();
		void get_float();
		void get_double();
};

#endif
