/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:35:29 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/11 18:58:34 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
   		 
	public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &ref);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &a);

		void execute(Bureaucrat const & executor) const; 
};

#endif
