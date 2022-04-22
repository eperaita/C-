/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:59:49 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:27:01 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(): Form("Unknown", "No target", 25, 5)
{
    std::cout << "     PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("PresidentialPardonForm", target , 25, 5)
{
    std::cout << "     PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "     PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref): Form(ref)
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
	 	throw Form::GradeTooLowException();
	}
	if (!this->getSigned())
    {
    	std::cout << "          > " << this->name << " has failed:"; 
	 	throw Form::NotSignedException();
	}
	else //success
	{
    	std::cout << "          > " << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
		
}

