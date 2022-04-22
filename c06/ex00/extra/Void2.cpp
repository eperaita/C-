/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:48 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/21 18:27:06 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Void.hpp"
#include <cstring>


Void::Void(std::string &str): _str(str)
{
	//std::cout << "Constructor called" << std::endl;
	check = 0;
	this->filter_data(); //aqui entra y filtra, y convierte a cada dato. 
}

Void::~Void()
{
	//std::cout << "Destructor called" << std::endl;

}

////////////////GETTERS///////////////////

void Void::getdata()
{
		if (c < 32 || c > 126)
			std::cout << "char : Non displayable" << std::endl; 
		else
			std::cout << "char :" << c << std::endl; 
		std::cout << "int :" << i << std::endl; 
		//ES EL PUTO FIXED SETPRECISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		std::cout <<  std::fixed << std::setprecision(1) << "float :" << f << "f" << std::endl; 
		std::cout <<  std::fixed << std::setprecision(1) << "double :" << d << std::endl; 
}

//////////////AUX PRIVATE FUNCTIONS///////////

void Void::filter_data()
{
	if (!_str.compare("-inff") || !_str.compare("-inf") || !_str.compare("nan") || !_str.compare("+inff") || !_str.compare("+inf")) //no cambia check y va a default
	{
		std::cout << "Es -+inf o -+inff o nan" << std::endl; 
		set_special();
		return ;
	}

	if (_str[0] == '-' || isdigit(_str[0])) 
	{
		if (_str.find('.') != std::string::npos)
		{
			if (_str.at(_str.length() - 1) == 'f')
			{
				std::cout << "Es float" << std::endl; 
				check = 3;	
			}
			else
			{
				std::cout << "Es double" << std::endl; 
				check = 4;
			}
		}
		else 
		{
			std::cout << "Es int" << std::endl; 
			check = 2;
		}
	}
	else
	{
		if (_str.size() > 1)
		{
			std::cout << "String of too much characters" << std::endl; 
			return;
		}
		std::cout << "es char" << std::endl; 
		check = 1;
	}
	convert_data(check);
	getdata();
}

void Void::set_special(std::string spec)
{
	if (!spec.compare("-inff"))
	{
		temp[0] ="impossible";
		temp[1] = "-inf";
		temp[2] = "-inff";
		temp[3] = "-inf";
	}
	else if (!spec.compare("-inf")) 
	{
		temp[0] ="impossible";
		temp[1] = "-inf";
		temp[2] = "-inff";
		temp[3] = "-inf";
	}
	else if (!spec.compare("nan"))
	{
		temp[0] ="impossible";
		temp[1] ="nan";
		temp[2] = "nanf";
		temp[3] = "nan";
	}
	else if (!spec.compare("+inff")) 
	{
		temp[0] ="impossible";
		temp[1] ="+inf";
		temp[2] = "+inff";
		temp[3] = "+inf";
	}
	else if (!spec.compare("+inf"))
	{
		temp[0] ="impossible";
		temp[1] ="+inf";
		temp[2] = "+inff";
		temp[3] = "+inf";
	}
	std::cout << "char :" << temp[0] << std::endl; 
	std::cout << "int :" << temp[1] << std::endl; 
	std::cout << "float :" << temp[2] << std::endl; 
	std::cout << "double :" << temp[3] << std::endl; 


}

void Void::convert_data(int check)
{

	//QUE PRECISION TIENE UN DOUBLE???

	switch(check)
	{
		case 1: //char
		{
			c = _str[0];
			//ESTO NO FUNCIONA
			//i = static_cast<int>(c);
			/*i = ;
			f = ;
			d = ;*///se pueden castear chars a digits???
			
			break;	
		}
		case 2: //int
		{
			i = atoi(_str.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		
			break;	
		}
		case 3: //float
		{
			f = static_cast<float>(atof(_str.c_str()));
			//c no se puede no?;
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		
			break;	
		}
		case 4: //double
		{
			d = atof(_str.c_str());
			//c no se puede no?;
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		
			break;	
		}
		case 0: //double
		{
			set_special(_str);
		}
		default://es nan, +-inf o -+inff
		{
			set_special(_str);
		}
	}



}


////////////////FILTER DATA/////////////////

 //A ver: Esta gestion d errores es muy basica, se quedan fuera cosas como:
    //  ./convert -14.55444fff
    //  ./convert 455grge45646
    //  ./convert 5.
    //  ./convert .7
    //Ademas es muy guarra con comprobaciones explicitas.if, elseif, compare....

    //Aparte, no esta gestionado los chars al completo:
    //  string de mas de un char
    //  non printable(fuera de 32-126)

    //Tambien hay que gestionar en digits :
    //  -inff, +inff and nanf
    //de modo que entra en la gestion de chars o incluir + y - en la de digits

