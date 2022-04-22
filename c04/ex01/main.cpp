/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:05:31 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:10:46 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	int i;
	const Animal *array[10];

	std::cout << "----- CREATE ARRAY OF ANIMALS (Half of Cats / Half of Dogs) ------" << std::endl << std::endl;
   	i = -1;
	while (++i < 10)
	{
		if (i % 2)
		{
			array[i] = new Dog();
		}
		else
			array[i] = new Cat();
		std::cout << "          [" << i << "] " << array[i]->getType() << " : ";
   		array[i]->makeSound();
		std::cout << std::endl;
	}
	
	std::cout << "------ DELETE ARRAY OF ANIMALS -----" << std::endl << std::endl;
	
	i = -1;
	while (++i < 10)
	{
		if (i % 2)
			delete array[i];
		else
			delete array[i];
		std::cout << std::endl;
	}
	
	std::cout << "------ DEEP COPY OF THE IDEAS for each Animal (HEAP) -----" << std::endl << std::endl;

	//deep copy, hereda el Brain *b de madre, que esta alojado en heap. DEEP copy debe hacer su propia copia, no simplemente apuntar al mismo address, lo hago en el constructor de Cat/Dog. 

    const Animal *a = new Cat();
    std::cout << " ->" << a->getType() << " -> " << a->getBrain(5) << std::endl;
    std::cout << " ->" << a->getType() << " -> " << a->getBrain(16) << std::endl;
	std::cout << std::endl;
    const Animal *b = new Dog();
    std::cout << " ->" << b->getType() << " -> " << b->getBrain(7) << std::endl;
    std::cout << " ->" << b->getType() << " -> " << b->getBrain(33) << std::endl;
    
	std::cout << "------ DEEP COPY OF THE IDEAS for each Animal (STACK) -----" << std::endl << std::endl;
	
	Dog aa;
	Dog bb;
	aa.setBrain(5, "tururuuuuuuu");
   	bb = aa;
    std::cout << " ->" << aa.getType() << " -> " << aa.getBrain(5) << std::endl;
    std::cout << " ->" << bb.getType() << " -> " << bb.getBrain(5) << std::endl;
	//Siendo un puntero tipo Animal puedo meterle Dog o Cat, es una clase abstracta, pero tengo que declarar los method o virtual functions en Animal, aunque no las defina, sino no me deja llamar a esas funciones aunque sea un Cat o Dog y las tengan. 

	std::cout << std::endl;
	std::cout << "------ DELETE ALLOCATED ANIMALS (HEAP)-----" << std::endl << std::endl;
	
	delete a;
	std::cout << std::endl;
	delete b;
	
	std::cout << std::endl;
	std::cout << "------ DELETE ALLOCATED ANIMALS (STACK) -----" << std::endl << std::endl;

	return 0;
}
