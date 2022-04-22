/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_comments.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:09:39 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 18:34:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() 
//Cant do inizialize list (strigns and pointers) here. Why?Cause you can only use the inizialize list in the declaration of the variable.   
//-> std::string forms [] = {"ShrubberyForm", "RobotomyRequestForm", "PresidentialPardonForm"}; 
{

	//I would instantiate the array of pointers here, but doesent alloc correctly, whe i call them throw the method, bad memory access. 	
	/*ptr p[] = {&Intern::createS, &Intern::createR, &Intern::createP};
	f = p;*/
	forms[0] = "shrubberycreation";
	forms[1] = "shrubbery creation";
   	forms[2] = "robotomyrequest";
   	forms[3] = "robotomy request";
	forms[4] = "presidentialpardon";
	forms[5] = "presidential pardon";
    std::cout << "     Intern  Default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "     Intern Destructor called" << std::endl;
}

Intern::Intern(Intern const &ref)
{
    std::cout << "     Intern Copy constructor called" << std::endl;
    *this = ref;
}

/*Intern &Intern::operator=(Intern const &ref)
{
    std::cout << "     Intern Assignation operator called" << std::endl;

    return (*this);
}*/

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i;

	std::transform (form.begin(), form.end(), form.begin(), ::tolower);
	i = 0;
    while (i < 6 && form != forms[i])
        i++;

	//Assign the array of pointers to functions. May be more apropiate do it in the constructor, but i cant//
	//Need to declare a new array, cause i cant do the initialize list after instantiating it
	////If I assign to f[0] = &Intern::createS; causes a bad read memory access. ??
	ptr f[] = {&Intern::createS, &Intern::createR, &Intern::createP};
	
	if (i == 6)
		throw Intern::FormNotFoundException();
	i /= 2;
/* En vez de punteros a funcion miembro, el array llevaria punteros a constructores*/
//	ptr f[] = {&ShrubberyCreationForm::ShrubberyCreationForm, &RobotomyRequestForm::RobotomyRequestForm, &PresidentialPardonForm::PresidentialPardonForm};
	
	///Return the call to funtion of the array of pointers[i]///
	std::cout << "     Intern creates" << form << std::endl;
    return((this->*(f[i]))(target));

}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("     > Form not found");
}

/////////////////////////////////////////////////////////

AForm *Intern::createS(std::string target)
{		
	return (new ShrubberyCreationForm(target));

}
AForm *Intern::createR(std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::createP(std::string target)
{
	return (new PresidentialPardonForm(target));
}



