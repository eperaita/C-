/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:21:48 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/06 17:37:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        //Cure(std::string const & type);
        ~Cure();
        Cure(Cure const &ref);

        Cure &operator=(Cure const &a);

        AMateria* clone() const; //why need to declare if it is inherited????
        void use(ICharacter& target);
};

#endif
