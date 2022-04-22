/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:09:39 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 18:34:14 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << "     Intern  Default constructor called" << std::endl;

	forms[0] = "shrubberycreation";
	forms[1] = "shrubbery creation";
   	forms[2] = "robotomyrequest";
   	forms[3] = "robotomy request";
	forms[4] = "presidentialpardon";
	forms[5] = "presidential pardon";
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

Intern &Intern::operator=(Intern const &ref)
{
    std::cout << "     Intern Assignation operator called" << std::endl;
	(void)ref;
    return (*this);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i;

	std::transform (form.begin(), form.end(), form.begin(), ::tolower);
	ptr f[] = {&Intern::createS, &Intern::createR, &Intern::createP};
	
	i = 0;
    while (i < 6 && form != forms[i])
        i++;
	if (i == 6)
		throw Intern::FormNotFoundException();
	i /= 2;
	
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



