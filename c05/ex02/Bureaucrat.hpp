/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:05:45 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:26:22 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
class Form;
class Bureaucrat
{
    private:
		const std::string name;
		int grade;

    public:

        Bureaucrat();
        Bureaucrat(std::string const &n, int g);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &ref);

        Bureaucrat &operator=(Bureaucrat const &a);

		const std::string getName() const;
		int getGrade() const;
		void gradePlus();
		void gradeMinus();
		
		void signForm(Form &f);
		void executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif
