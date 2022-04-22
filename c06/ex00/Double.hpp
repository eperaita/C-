/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:00:47 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 18:48:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOUBLE_HPP
#define DOUBLE_HPP


#include "Void.hpp"
class Double : public Void
{
	public:
		Double(std::string &str);
		~Double();
		
		void get_char();
		void get_int();
		void get_float();
		void get_double();
};

#endif
