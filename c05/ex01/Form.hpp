/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:47:26 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:01:39 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
		const std::string name;
		bool _signed;
		const int g_sign;
		const int g_exe;

    public:
        Form();
        Form(std::string const &n, int sign, int exe);
        ~Form();
        Form(Form const &ref);

        Form &operator=(Form const &a);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExe() const;
		void beSigned(Bureaucrat const &who);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();	
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &b);

#endif
