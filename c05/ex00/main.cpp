/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:02:15 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 18:41:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp" 
#include <stdexcept>

int main(void)
{
	std::cout << std::endl;
	std::cout << "TRY TO CREATE A BUROCRAT -STACK-" << std::endl;
	std::cout << "[ Success, create , do stuff (increment/decrement grade) and delete in this scope of the try. ]" << std::endl;
    std::cout << std::endl;
    
	try
	{
		Bureaucrat a("Stack", 5);	
		std::cout << a;
		a.gradePlus();
		std::cout << a;
		a.gradeMinus();
		std::cout << a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }	

	std::cout << std::endl;
    std::cout << "TRY TO CREATE A BUROCRAT -HEAP-" << std::endl;
    std::cout << "[ Success, create , do stuff (increment/decrement grade) but must be deleted in main]" << std::endl;
    std::cout << std::endl;

	Bureaucrat *p1;
	p1 = NULL;
    try
    {
        p1 = new Bureaucrat("Heap", 68);
        //p1 = new Bureaucrat("Heap", 200);
        std::cout << *p1;
		p1->gradePlus();
		std::cout << *p1;
		p1->gradeMinus();
        std::cout << *p1;
    }
    catch (std::exception & e)
	{
		std::cout << e.what() << std::endl; //calls what() of the object std::exception received, each exception has defined its own
	}
	
	if (p1) //if the try goes to an exception must no delete unallocated item
		delete p1;

    
	std::cout << std::endl;
	std::cout << "TRY TO CREATE BUROCRATS with an error on creation" << std::endl;
	std::cout << "[ 2 Success, the third go to exception and goes out. No more Burocrats are created. ]" << std::endl;
    std::cout << std::endl;

	try
    {
		Bureaucrat b("B1", 17);	
		Bureaucrat c("B2", 96);	
		Bureaucrat d("B3", 155);	//more than 150
		//Bureaucrat d("B3", 0);	//less than 1
		Bureaucrat e("B4", 34);	

        std::cout << b;
        std::cout << c;
        std::cout << d;
        std::cout << e;
    }
    catch (std::exception & e)
    {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "TRY TO CREATE BUROCRATS with an error in increment or decrement" << std::endl;
	std::cout << "[ 2 Success, the third go to exception and goes out. No more Burocrats are created. ]" << std::endl;
    std::cout << std::endl;

	 try
    {
        Bureaucrat f("Bureaucrat", 1);
        std::cout << f;
		f.gradePlus();
        std::cout << f;
		f.gradeMinus();
        std::cout << f;
    }
    catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
