/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:09:59 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 17:57:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private: 
		//void *input; // no funciona con void * , no es casteable a string, o a float con reinterpret_cast?? Templates? auto -> c11
		float fl;
		std::string str;
	public: 
		Data();
		Data(float in);
		Data(std::string in);
		Data(Data & ref);
		~Data();
		
		std::string get_input();
		float get_float();
	
};



#endif
