/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:11:50 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/11 18:58:26 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
	private:
    
	public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &ref);

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &a);

		void execute(Bureaucrat const & executor) const; 
};

#endif
