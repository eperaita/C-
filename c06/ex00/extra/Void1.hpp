/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:08:37 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/21 18:53:52 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_HPP
#define VOID_HPP

class Void
{
	private:
		std::string _str;
	//	void *s;
		
		char c;
		int i;
		float f;
		double d;
		int check;
		std::string temp[4];
		
		void convert_data(int check);
		void filter_data();
		
		
		void set_special(std::string spec);
	public:
		Void(std::string &str);
		~Void();

		 void getdata();
};



#endif
