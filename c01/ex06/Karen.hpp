/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:33:03 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 14:09:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>


class Karen
{
	private:
		std::string _level[4];
		void isdefault( void );
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string _str[4];
		void (Karen::*f)(void);
		//std::map<std::string, int> map;
	public:
		Karen();
		void complain( std::string level );

};
#endif
