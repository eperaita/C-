/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:01:19 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/24 19:21:45 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Void.hpp" 
#include "Float.hpp" 
#include "Special.hpp"
#include "Int.hpp" 
#include "Double.hpp" 
#include "Char.hpp" 

 int main(int argc, char **argv)
{
	int i = 0;
	if (argc != 2)
	{
		std::cout << "Bad arguments." << std::endl;
		return 1;
	}
	
	std::string str = argv[1]; 
	
	Void *v;
	v = NULL;

	if (!str.compare("-inff") || !str.compare("-inf") || !str.compare("nan") || !str.compare("nanf") || !str.compare("+inff") || !str.compare("+inf")) //SPECIAL
		v = new Special(str);
	else if (((str[0] == '-' || str[0] == '+') && isdigit(str[1])) ||( isdigit(str[0]))) //DIGIT (INT - FOAT - DOUBLE)
	{
		while (str[++i])
		{
			if (isdigit(str[i]) || str[i] == '.' || (str[i] == 'f' && !str[i + 1]))
				continue;
			else
			{
				std::cout << "Not a valid number" << std::endl; 
				exit(1);
			}
		}
		if (str.find('.') != std::string::npos)
		{
			if (!isdigit(str[str.find('.') + 1]))
			{
				std::cout << "Not a valid number" << std::endl; 
				exit(1);
			}
			else if (str.at(str.length() - 1) == 'f')
				v = new Float(str);
			else 
				v = new Double(str);
		}
		else 
			v = new Int(str);
	}
	else //CHARS
	{
		if (str.size() > 1)
		{
			std::cout << "String of too much characters" << std::endl; 
			exit(1);
		}
		v = new Char(str);
	}

	v->get_char();
	v->get_int();
	v->get_float();
	v->get_double();


	delete v;
}
