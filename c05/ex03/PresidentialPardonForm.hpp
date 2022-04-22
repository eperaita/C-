/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:50:59 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/11 18:58:28 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
   	 
	public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &ref);

        PresidentialPardonForm &operator=(PresidentialPardonForm const &a);

		void execute(Bureaucrat const & executor) const; 
	};

#endif
