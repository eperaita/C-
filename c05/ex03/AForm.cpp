/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:47:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/13 19:56:06 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <stdexcept>

AForm::AForm(): name("Unknown"), target("No Target"), _signed(false), g_sign(150), g_exe(150)
{
    std::cout << "     AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &n, std::string const &target, int sign, int exe): name(n), target(target), _signed(false), g_sign(sign), g_exe(exe)
{
    std::cout << "     AForm parameter constructor called" << std::endl;

    if(sign < 1 || exe < 1)
        throw AForm::GradeTooHighException(); 
    else if(sign > 150 || exe > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{

    std::cout << "     AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &ref): _signed(false),  g_sign(ref.getGradeSign()), g_exe(ref.getGradeExe())
{
    std::cout << "     AForm copy constructor called" << std::endl;
    *this = ref;
}

AForm &AForm::operator=(AForm const &ref)
{
    std::cout << "     AForm assignation operator called" << std::endl;

    this->_signed = ref.getSigned();
    return (*this);
}

//////////////////////GETTERS///////////////////

const std::string AForm::getName() const
{
    return (this->name);
}
const std::string AForm::getTarget() const
{
    return (this->target);
}

bool AForm::getSigned() const 
{
    return (this->_signed);
}

int AForm::getGradeSign() const
{
    return (this->g_sign);
}

int AForm::getGradeExe() const
{
    return (this->g_exe);
}

//////////////////////////////////////////////////

void AForm::beSigned(Bureaucrat const &who)
{
	if (who.getGrade() > this->getGradeSign())
        throw AForm::GradeTooLowException();
	else 
	{
		this->_signed = true;
        std::cout << "     " << who.getName() << " signs " << this->name << std::endl;
	}
}

//////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
    out << "          -> " << f.getName() << ": -> Target: "<< f.getTarget() << " -> Signed: "<< f.getSigned() << " -> Grade to sign: " <<  f.getGradeSign() << " -> Grade to execute: " <<  f.getGradeExe() << std::endl;
    return (out);
}


/////////////////EXCEPTIONS////////////////////

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("          > grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("          > grade too low!");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("          > not signed!");
}
