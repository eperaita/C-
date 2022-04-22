/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:05:31 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/04 20:12:50 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----- BASE ANIMAL CANNOT BE INSTANTIABLE ------" << std::endl << std::endl;

    //const Animal *a = new Animal();
	//a->makeSound();
    //const Animal b;
	//b.makeSound();

	std::cout << "----- A TYPE BASED ON ANIMAL CAN BE INSTANTIATED ------" << std::endl << std::endl;

    const Animal *c = new Dog();
	c->makeSound();
	
	std::cout << std::endl;
	std::cout << "----- DEEP COPY STILL WORKS ------" << std::endl << std::endl;
	
	Cat c1;
	Cat c2;
	c1.setBrain(2, "yeeeepppp");
	c2 = c1;
	std::cout << c1.getBrain(2) << std::endl;
	std::cout << c2.getBrain(2) << std::endl;
	
	std::cout << std::endl;
	std::cout << "------ DELETE ALLOCATED ANIMALS -----" << std::endl << std::endl;
	
//	delete a;
//	std::cout << std::endl;
	delete c;

	return 0;
}

/*int main(){
    Animal  *all[10];

    std::cout << "\n-----------------Create Animals---------------------\n\n";
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            all[i] = new Dog();
        else
            all[i] = new Cat();
        std::cout << "\n----looooop-------\n\n";

    }
    std::cout << "\n-----------------Deep Copy---------------------\n\n";

    Dog *one = new Dog();
    one->getBrain(2);
	std::cout << one->getBrain(2) << std::endl;
	one->setBrain(2, "yeeeepppp");
	std::cout << one->getBrain(2) << std::endl;
    Dog *two = new Dog();
    *two = *one;
    delete one;
	std::cout << two->getBrain(2) << std::endl;
    delete two;




    std::cout << "\n-----------------Destroy Animals---------------------\n\n";
    for (int i = 0; i < 10; i++)
        delete all[i];
    std::cout << "\n-----------------Destroy Array---------------------\n\n";
    return 0;
}*/
