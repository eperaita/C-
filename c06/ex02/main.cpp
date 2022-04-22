/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:30:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/31 19:45:42 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base * generate(void)
{
	srand (time(NULL));
	int i = rand() % 100;//random number
	//me gustaria de nuevo hacer un puntero a constructores... pero no es posible???
	std::cout << std::endl;
	std::cout << "Random number : " << i << std::endl;
	std::cout << std::endl;
	if (i % 3 == 0)
		return (new A());
	else if (i % 3 == 1)
		return (new B());
	else
		return (new C());
};

void identify(Base* p) //Point
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
};
void identify(Base& p) //Reference
{
	try {
		Base &ref = dynamic_cast<A &>(p);	
		std::cout << "A" << std::endl;
		return ;	
		(void)ref;
	}
	catch(std::bad_cast & e){
		//std::cout << "Not Casteable" << std::endl;	
	}
	try {
		Base &ref = dynamic_cast<B &>(p);	
		std::cout << "B" << std::endl;	
		return ;	
		(void)ref;
	}
	catch(std::bad_cast & e){
		//std::cout << "Not Casteable" << std::endl;	
	}
	try {
		Base &ref = dynamic_cast<C &>(p);	
		std::cout << "C" << std::endl;	
		return ;	
		(void)ref;
	}
	catch(std::bad_cast & e){
		//std::cout << "Not Casteable" << std::endl;	
	}
}

int main()
{

	Base *p = generate();

	std::cout << "POINTER:" << std::endl;

	identify(p);
	
	std::cout << "REFERENCE:" << std::endl;
	
	identify(*p);

	delete p;
	return (0);
}
