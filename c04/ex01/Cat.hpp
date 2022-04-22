/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/08 18:03:46 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *b;
    public:
        Cat();
        ~Cat();
        Cat(Cat const &ref);

		std::string getType() const; 
		void makeSound() const;
		std::string getBrain(int i) const;
		void setBrain(int i, std::string idea);

        Cat &operator=(Cat const &c);

};

#endif

