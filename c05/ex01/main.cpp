/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:02:15 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:02:44 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp" 
#include "Form.hpp" 
#include <stdexcept>

int main(void)
{

	//crear un bureaucrat, firmar un form con un grado ok, uno menor y uno mayor. 
	//tambien a crear un form con grado de firma superior o inferior. 
	//las excepciiones tienen que estar definidas tambien ne form?
	//dependencias circulares: form depende de Bureaucrat y viceversa. Ñapa de Character???
	//

	std::cout << std::endl;
	std::cout << "---------TRY TO CREATE FORMS-------" << std::endl;
    std::cout << std::endl;
    
	try
	{
		Form f1("T10!", 3, 5);
		std::cout << f1;
		Form f2("T11!", 70, 65);
		std::cout << f2;
		Form f3("T12!", 160, 5);
		std::cout << f3;
		//Form f4("T10!", 160, 0);
		//std::cout << f4;

	}
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }	


	std::cout << std::endl;
    std::cout << "---------MAKE A BUREAUCRAT TO SIGN FORMS-------" << std::endl;
    std::cout << std::endl;

    try
    {
		Bureaucrat a("Eperaita", 50);
        Form aa("T28", 100, 100);
		a.signForm(aa);
		std::cout << aa;

    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << std::endl;
    std::cout << "---------MAKE A BUREAUCRAT TO SIGN FORM WITH INVALID GRADE-------" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat a("Eperaita", 149);
        Form aa("T28", 100, 100);
        a.signForm(aa);
        std::cout << aa;

    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }


	return 0;
}
