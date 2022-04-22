/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:42:19 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 17:38:57 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "easyfind.hpp"

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
	std::list<int>::iterator it = lst.begin();

	while (it != lst.end())
    {
        std::cout <<" [" << *it << "]";
        it++;
    }
	std::cout << std::endl;

	int to_find = 42;
	std::cout << "Position of " << to_find << " -> ";
	try
	{
		it = easyfind(lst, to_find);
		std::cout << std::distance(lst.begin(), it) << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl; //CERROR
	}


	to_find = 45678;
	std::cout << "Position of " << to_find << " -> ";
	 try
    {
        it = easyfind(lst, to_find);
		std::cout << std::distance(lst.begin(), it) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;

	///////////////////VECTOR////////////////
	std::cout << "-> VECTOR <-" << std::endl;
	std::vector<int> vec(10, 0);
	std::vector<int>::iterator itv = vec.begin();

	while (itv != vec.end())
	{
		*itv = rand() % 10;
		std::cout <<" [" << *itv << "]";
		itv++;
	}
	std::cout << std::endl;
	
	int int_find = 3;
	std::cout << "Position of " << int_find << " -> ";
	try
	{
		itv = easyfind(vec, int_find);
		std::cout << std::distance(vec.begin(), itv) << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl; 
	}


	int_find = 45678;
	std::cout << "Position of " << int_find << " -> ";
	 try
    {
        itv = easyfind(vec, int_find);
		std::cout << std::distance(vec.begin(), itv) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;

	///////////////////MAP////////////////
	std::cout << "-> MAP <-" << std::endl;
    std::map<std::string, int> map;
	map["one"] = rand() % 10;
	map["two"] = rand() % 10;
	map["three"] = rand() % 10;
	map["four"] = rand() % 10;
	map["five"] = rand() % 10;
    std::map<std::string, int>::iterator itm = map.begin();
	while (itm != map.end()) //The order of the array is key-order!!!!!
    {
        std::cout <<" [" << itm->first << "] [" << itm->second << "] //";
        itm++;
    }
    std::cout << std::endl;
	
   	int_find = 7;

    std::cout << "Position of " << int_find << " -> ";
    try
    {
        itm = easyfind(map, int_find);
        std::cout << std::distance(map.begin(), itm) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }


    int_find = 3;
    std::cout << "Position of " << int_find << " -> ";
     try
    {
        itm = easyfind(map, int_find);
        std::cout << std::distance(map.begin(), itm) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;
	
	return 0;
}
