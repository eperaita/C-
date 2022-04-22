/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:21:41 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/14 23:49:34 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void ) {
	
	int i ;

	///////// ITER cubed() with ints///////
	std::cout << std::endl;
	std::cout << "      -> ITER with ints and cubed()" << std::endl;
	int array[10] = {3, 55, 65, 16, 22, 7, 0, -12, 765, 33};
	std::cout << std::endl;
	i = -1;
	while (++i < 10)
		std::cout << "array  = " << array[i] << std::endl;

	std::cout << std::endl;
	::iter<int>(array, 10, ::cubed<int>);
	i = -1;
	while (++i < 10)
		std::cout << "array  = " << array[i] << std::endl;
	
	std::cout << std::endl;
	
	///////// ITER squared with doubles///////
	
	std::cout << "      -> ITER with doubles and squared()" << std::endl;
	double second[10] = {3.2, 55.009, 65.32, 16.0, 22, 7.78, 0.22, -12.08, 765, 33.087};
	std::cout << std::endl;
	i = -1;
	while (++i < 10)
		std::cout << "array  = " << second[i] << std::endl;
	
	std::cout << std::endl;
	::iter<double>(second, 10, ::squared<double>);
	i = -1;
	while (++i < 10)
		std::cout << "array  = " << second[i] << std::endl;
	
	std::cout << std::endl;

	///////// ITER print with strings///////
	std::cout << "      -> ITER with strings and print()" << std::endl;
	std::string str[6] = {"one", "two", "three", "four", "five", "six"};
    std::cout << std::endl;
    ::iter<std::string>(str, 6, ::print<std::string>);	
	
	std::cout << std::endl;
	return 0;
}
