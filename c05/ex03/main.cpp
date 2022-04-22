/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:02:15 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:37:00 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp" 
#include "Intern.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "PresidentialPardonForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include <stdexcept>

int main(void)
{

	std::cout << std::endl;
	std::cout << "---------CREATE INTERN AND ASK FOR FORMS-------" << std::endl;
    std::cout << std::endl;
    
	Intern someRandomIntern;
	AForm* rrf;
	AForm* rrf2;
	AForm* rrf3;
	
	rrf = NULL;
	rrf2 = NULL;
	rrf3 = NULL;
	try
	{
		rrf = someRandomIntern.makeForm("PresidentialPardon", "Bender");
		std::cout << *rrf;
		rrf2 = someRandomIntern.makeForm("RobotomyRequest", "Bender");
		std::cout << *rrf2;
		rrf3 = someRandomIntern.makeForm("ShrubberyCreation", "Bender");
		std::cout << *rrf3;
		rrf3 = someRandomIntern.makeForm("Random", "Bender"); //will throw an exception, does not match
		std::cout << *rrf3;
	}
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
	
		std::cout << std::endl;
		if (rrf)
			delete rrf;
		if (rrf2)
			delete rrf2;
		if (rrf3)
			delete rrf3;

	std::cout << std::endl;
    std::cout << "---------CREATE BUREAUCRAT, ASK FOR FORM, SIGN AND EXECUTE-------" << std::endl;
    std::cout << std::endl;

    AForm* form;

    form = NULL;
    try
    {
		Bureaucrat ep("Eperaita", 2);
        form = someRandomIntern.makeForm("Presidential Pardon", "Bender");
        std::cout << *form;
		ep.signForm(*form);
		ep.executeForm(*form);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

        std::cout << std::endl;
        if (form)
            delete form;

	return 0;
}

