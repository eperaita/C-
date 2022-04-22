/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/04 13:12:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal const &ref);

		std::string getType() const; 
        void makeSound() const;

        WrongAnimal &operator=(WrongAnimal const &a);

};

#endif

