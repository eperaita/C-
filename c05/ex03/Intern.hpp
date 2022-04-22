/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:09:24 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:36:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Intern
{
	protected:
		typedef AForm *(Intern::*ptr)(std::string form);
		ptr *p;
		std::string forms[6];
    public:
        Intern();
        ~Intern();
        Intern(Intern const &ref);

        Intern &operator=(Intern const &a);

		AForm *makeForm(std::string form, std::string target);
		AForm *createS(std::string target);
		AForm *createR(std::string target);
		AForm *createP(std::string target);
		class FormNotFoundException : public std::exception
		{
			virtual const char* what() const throw();	
		};
};


#endif
