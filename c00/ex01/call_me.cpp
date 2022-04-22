/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_me.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:25:42 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 19:12:27 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "phonebook.hpp"
#include <iomanip>

Contact::Contact(void){};//Constructor
PhoneBook::PhoneBook(void){ filled = 0; };//Constructor
PhoneBook::~PhoneBook(void){};//Destructor

void Contact::set_contact(std::string na, std::string l, std::string ni, std::string p, std::string d)
{
	first_name = na;
	last_name = l;
	nickname = ni;
	phone = p;
	darkest_secret = d;
	return ;
}

std::string check_length(std::string str)
{
	std::string temp;

	 if (str.length() > 10)
    {
        temp = str.substr(0, 9);
        temp.append(".");
		return (temp);
    }
	return(str);
}

int check_num(std::string str)
{
	if(str[0] && !str[1] && isdigit(str[0]))
		return (1);
	return(0);
}

void Contact::get_list(int i)
{
	std::cout << std::right << std::setw(11) << i << "|";
	std::cout << std::setw(11) << check_length(first_name) << "|" ;	
	std::cout << std::setw(11) << check_length(last_name) << "|" ;
   	std::cout << std::setw(11) << check_length(nickname) << "|"; 
	std::cout << std::endl;
	return ;

}
void Contact::get_contact(void)
{

	std::cout << "Name: "<< first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone: "<< phone << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
	return ;
}

void PhoneBook::add(int i)//GUARDA SI SON DOS PALABRAS!
{
	std::string temp[5];
	
	std::cout << "Name:"<< std::endl;
	std::getline(std::cin >> std::ws, temp[0]);
	std::cout << "Last name:" << std::endl;
	std::getline(std::cin >> std::ws, temp[1]);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin >> std::ws, temp[2]);
	std::cout << "Phone:" << std::endl;
	std::getline(std::cin >> std::ws, temp[3]);
	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin >> std::ws, temp[4]);
	c[i].set_contact( temp[0], temp[1], temp[2], temp[3], temp[4]);
	std::cout << "--Added--" << std::endl;
	if (filled < 8)
		filled++;
	return ;
}

void PhoneBook::search(void)
{
	int i;
	std::string f;

	if (!filled)
	{
		std::cout << "--You dont have any contact--" << std::endl;
		return ;
	}
	else
	{
		i = -1;
   		while (++i < filled)
			c[i].get_list(i);
		std::cout << "--Who are you looking for?--" << std::endl;
		std::cin >> f;
		if (!std::isdigit(f[0]) || f.size() > 1)
		{
			std::cout << "--Not an option--" << std::endl;
			return ;
		}
		i =  atoi(f.c_str());
		if( i < filled)
			c[i].get_contact();
		else
		{
            std::cout << "--Not an option--" << std::endl;
            return ;
        }

	}
	return;
}

