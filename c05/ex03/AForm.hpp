/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:47:26 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/13 19:56:07 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	protected:
		const std::string name;
		const std::string target;
		bool _signed;
		const int g_sign;
		const int g_exe;

    public:
        AForm();
        AForm(std::string const &n, std::string const &target, int sign, int exe);
        virtual ~AForm();
        AForm(AForm const &ref);

        AForm &operator=(AForm const &a);

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

std::ostream &operator<<(std::ostream &out, AForm const &b);

#endif
