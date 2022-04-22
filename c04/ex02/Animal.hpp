/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:19:28 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

//This is an abstrac class, cannot be instantiable. 
//What determines that is an abstract class? -> having a pure method (= 0)

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        Animal(Animal const &ref);

		std::string getType() const; 
		//if we comment these pure methods, the class becomes non abstract and can be instantiated. Try it!
        virtual void makeSound() const = 0;
		virtual std::string getBrain(int i) const = 0;

        Animal &operator=(Animal const &a);

};

#endif

