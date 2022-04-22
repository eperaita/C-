/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:00:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 18:59:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHAR_HPP
#define CHAR_HPP


#include "Void.hpp"
class Char: virtual public Void
{
	public:
		Char(std::string &str);
		~Char();
		
		void get_char();
		void get_int();
		void get_float();
		void get_double();
};

#endif
