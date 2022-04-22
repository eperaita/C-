/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:35:29 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:27:14 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &ref);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &a);

		void execute(Bureaucrat const & executor) const; 
};

#endif
