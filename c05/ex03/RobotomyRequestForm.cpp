/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:33:45 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/13 19:09:38 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Unknown", "No target",  72, 45)
{
    std::cout << "     RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", target , 72, 45)
{
    std::cout << "     RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "     RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref): AForm(ref) 
		{
    std::cout << "     RobotomyRequestForm copy constructor called" << std::endl;
    *this = ref;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
    std::cout << "     RobotomyRequestForm assignation operator called" << std::endl;

    this->_signed = ref.getSigned();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
    	std::cout << "          > <...drilling sounds...> " << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;


}


