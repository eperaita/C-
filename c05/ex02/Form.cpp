/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:47:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:32:58 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <stdexcept>

Form::Form(): name("Unknown"), target("No Target"), _signed(false), g_sign(150), g_exe(150)
{
    std::cout << "     Form  Default constructor called" << std::endl;
}

Form::Form(std::string const &n, std::string const &target, int sign, int exe): name(n), target(target), _signed(false), g_sign(sign), g_exe(exe)
{
    std::cout << "     Form  Parameter constructor called" << std::endl;

    if(sign < 1 || exe < 1)
        throw Form::GradeTooHighException(); 
    else if(sign > 150 || exe > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{

    std::cout << "     Form Destructor called" << std::endl;
}

Form::Form(Form const &ref): _signed(false),  g_sign(ref.getGradeSign()), g_exe(ref.getGradeExe())
{
    std::cout << "     Form Copy constructor called" << std::endl;
    *this = ref;
}

Form &Form::operator=(Form const &ref)
{
    std::cout << "     Form Assignation operator called" << std::endl;

    this->_signed = ref.getSigned();
    return (*this);
}

//////////////////////GETTERS///////////////////

const std::string Form::getName() const
{
    return (this->name);
}
const std::string Form::getTarget() const
{
    return (this->target);
}

bool Form::getSigned() const 
{
    return (this->_signed);
}

int Form::getGradeSign() const
{
    return (this->g_sign);
}

int Form::getGradeExe() const
{
    return (this->g_exe);
}

//////////////////////////////////////////////////

void Form::beSigned(Bureaucrat const &who)
{
	if (who.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
	else 
	{
		this->_signed = true;
        std::cout << "     " << who.getName() << " signs " << this->name << std::endl;
	}
}

//////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Form const &f)
{
    out << "          -> " << f.getName() << ": -> Target: "<< f.getTarget() << " -> Signed: " << f.getSigned() << " -> Grade to sign: " <<  f.getGradeSign() << " -> Grade to execute: " <<  f.getGradeExe() << std::endl;
    return (out);
}


/////////////////EXCEPTIONS////////////////////

const char* Form::GradeTooHighException::what() const throw()
{
    return ("          > grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("          > grade too low!");
}

const char* Form::NotSignedException::what() const throw()
{
    return ("          > not signed!");
}
