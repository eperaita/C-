/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data_p.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:09:59 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 18:54:28 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private: 
		void *input;
	public: 
		Data();
		Data(float *in);
		Data(std::string *in);
		~Data();
		
		std::string *get_str();
		float *get_float();
	
};



#endif
