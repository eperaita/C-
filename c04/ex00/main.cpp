/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:05:31 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 20:54:39 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w = new WrongCat();
	const WrongCat* wc = new WrongCat();
	
	std::cout << std::endl;
	std::cout  << meta->getType() << " : ";
   	meta->makeSound();

	std::cout << std::endl;
	std::cout  << j->getType() << " : ";
   	j->makeSound();

	std::cout << std::endl;
	std::cout  << i->getType() << " : ";
   	i->makeSound();

	std::cout << std::endl;
	std::cout  << w->getType() << " : ";
   	w->makeSound();
	std::cout << std::endl;

	std::cout  << wc->getType() << " : ";
   	wc->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete w;
	delete wc;
	return 0;
}
