/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:42:19 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 20:01:40 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include "easyfind.hpp"

void print(int i)
{
	std::cout << i << std::endl;
}

int main(int, char**)
{

    std::cout << std::endl;
	///////////////////LIST////////////////
	std::cout << "-> LIST <-" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(17);
	lst.push_back(42);
	lst.push_back(4);

	for_each(lst.begin(), lst.end(), print);

	int to_find = 42;
	std::cout << "Position of " << to_find << " -> ";
	try
	{
		std::cout << std::distance(lst.begin(), easyfind(lst, to_find)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl; //CERROR
	}


	to_find = 45678;
	std::cout << "Position of " << to_find << " -> ";
	 try
    {
		std::cout <<  std::distance(lst.begin(), easyfind(lst, to_find)) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;

	///////////////////VECTOR////////////////
	std::cout << "-> VECTOR <-" << std::endl;
	std::vector<int> vec;
	vec.push_back(543);
	vec.push_back(-14);
	vec.push_back(42);
	vec.push_back(412);
	vec.push_back(3412);

	for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;
	
	to_find = 42;
	std::cout << "Position of " << to_find << " -> ";
	try
	{
		std::cout <<  *(easyfind(vec, to_find))<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl; 
	}


	to_find = 45678;
	std::cout << "Position of " << to_find << " -> ";
	 try
    {
		std::cout <<  *(easyfind(vec, to_find))<< std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;

	return 0;
}
