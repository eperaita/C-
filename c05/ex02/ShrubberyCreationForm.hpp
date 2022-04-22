/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:11:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:27:37 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
class ShrubberyCreationForm : public Form
{
	public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &ref);

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &a);

		void execute(Bureaucrat const & executor) const; 
};

#endif
