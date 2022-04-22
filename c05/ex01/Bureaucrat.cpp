/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:25:31 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:02:43 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat()
{
	std::cout << "     " <<  name << " Default constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(std::string const &n, int g): name(n)
{
	std::cout << "     " << name << " Parameter constructor called" << std::endl;

	if(g < 1)
		throw Bureaucrat::GradeTooHighException(); 
	else if(g > 150)
		throw Bureaucrat::GradeTooLowException();
	else
        grade = g;
}

Bureaucrat::~Bureaucrat(){

	std::cout << "     " << name << " Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref)
{
	std::cout << "     " << name << " Copy constructor called" << std::endl;
	*this = ref;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref)
{
	std::cout << "     " << name << " Assignation operator called" << std::endl;

    this->grade = ref.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::gradePlus()
{
	this->grade--;	
	if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
	std::cout << "     Grade increased"<< std::endl;
}
        
void Bureaucrat::gradeMinus()
{
	this->grade++;
	if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
	std::cout << "     Grade decreased"<< std::endl;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("          > Bureaucrat grade cannot assign that high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("          > Bureaucrat grade cannot assign that low!");
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
    out << "     ** Bureaucrat: " << b.getName() << " -> Grade: "<< b.getGrade() << " **"<< std::endl;
    return (out);
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
		f.beSigned(*this);
        std::cout << "     " << this->name << " signs " << f.getName() << std::endl;
	}
    catch(std::exception & e)
	{
        std::cout << "     " << this->name << " cannot sign " << f.getName() << " because:" << std::endl;
		std::cout << e.what() << std::endl;
		
	}
}
