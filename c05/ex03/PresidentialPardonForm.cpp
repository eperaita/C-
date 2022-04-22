/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:59:49 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/13 19:05:25 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Unknown", "No target", 25, 5)
{
    std::cout << "     PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", target , 25, 5)
{
    std::cout << "     PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "     PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref): AForm(ref)
{
    std::cout << "     PresidentialPardonForm copy constructor called" << std::endl;
    *this = ref;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
    std::cout << "     PresidentialPardonForm assignation operator called" << std::endl;

    this->_signed = ref.getSigned();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeExe())
    {
    	std::cout << "          > " << this->name << " has failed:"; 
	 	throw AForm::GradeTooLowException();
	}
	if (!this->getSigned())
    {
    	std::cout << "          > " << this->name << " has failed:"; 
	 	throw AForm::NotSignedException();
	}
	else //success
	{
    	std::cout << "          > " << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
		
}

