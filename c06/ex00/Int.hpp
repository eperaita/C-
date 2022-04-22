/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:00:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 18:47:49 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INT_HPP
#define INT_HPP


#include "Void.hpp"
class Int : public Void
{
	public:
		Int(std::string &str);
		~Int();
		
		void get_char();
		void get_int();
		void get_float();
		void get_double();
};

#endif
