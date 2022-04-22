/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:34:42 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/05 22:48:31 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    protected:
        std::string ideas[100];

    public:
        Brain();
        virtual ~Brain();
        Brain(Brain const &ref);

		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
        
		Brain &operator=(Brain const &a);

};

#endif
