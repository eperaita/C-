/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:00:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 18:48:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FLOAT_HPP
#define FLOAT_HPP


#include "Void.hpp"
class Float : public Void
{
	public:
		Float(std::string &str);
		~Float();
		
		void get_char();
		void get_int();
		void get_float();
		void get_double();
};

#endif
