/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:59:29 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 17:57:46 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include <cstdint> 
#include <iomanip>

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));	
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));	
}


int main()
{
	std::cout << std::endl;
	std::cout << "//////////////FLOAT////////////" << std::endl;
	std::cout << std::endl;
	
	float f = 0.02345678f;
	Data *ptr = new Data(f);

	
	//serialize

	uintptr_t ret = serialize(ptr);

	//deserialize

	Data *second = deserialize(ret);

	std::cout << "ADRESSES:" << std::endl;
	std::cout << "Data ptr address: "<< ptr << std::endl;
	std::cout << "Data second address: "<< second << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout << "Data ptr value: " << ptr->get_float() << std::endl;
	std::cout << "Data second value: " << second->get_float() << std::endl;
	std::cout << std::endl << std::endl;
	
	delete ptr;	

	std::cout << std::endl;
	std::cout << "//////////////STRING////////////" << std::endl;
	std::cout << std::endl;

	std::string h = "hola	";
	Data *ptr2 = new Data(h);

	//serialize

	uintptr_t ret2 = serialize(ptr2);

	//deserialize

	Data *other = deserialize(ret2);

	std::cout << "ADRESSES:" << std::endl;
	std::cout << "Data ptr2 add: "<< ptr2 << std::endl;
	std::cout << "Data other add: "<< other << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout << "Data ptr2 value: " << ptr2->get_input() << std::endl;
	std::cout << "Data other value: " << other->get_input() << std::endl;
	std::cout << std::endl << std::endl;

	delete ptr2;	
	
	return 0;
}
