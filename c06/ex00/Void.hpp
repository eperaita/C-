/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:08:37 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 19:01:21 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_HPP
#define VOID_HPP

class Void
{
	protected:
		std::string _str;
		
	public:
		Void();
		Void(std::string &str);
		virtual ~Void();
		
		virtual void get_char() = 0;
		virtual void get_int() = 0;
		virtual void get_float() = 0;
		virtual void get_double() = 0;
};



#endif
