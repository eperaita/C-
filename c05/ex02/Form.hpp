/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:47:26 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:32:57 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	protected:
		const std::string name;
		const std::string target;
		bool _signed;
		const int g_sign;
		const int g_exe;

    public:
        Form();
        Form(std::string const &n, std::string const &target, int sign, int exe);
        virtual ~Form();
        Form(Form const &ref);

        Form &operator=(Form const &a);

		const std::string getName() const;
		const std::string getTarget() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExe() const;
		void beSigned(Bureaucrat const &who);
		
		virtual void execute(Bureaucrat const & executor) const = 0; 

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();	
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &b);

#endif
