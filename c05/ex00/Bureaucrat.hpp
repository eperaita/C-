/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:05:45 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 18:40:33 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

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

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif
