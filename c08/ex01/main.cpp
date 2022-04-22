/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:31:18 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 02:02:12 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
int main(void)
{
	Span sp = Span(5);

	std::cout << "---> FILLING THE SPAM" << std::endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	std::cout << "---> FINDING THE SHORTEST/LONGEST SPAN" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
	Span spa = Span();	
	std::cout << "---> FILLING EFFICIENTLY" << std::endl;
		spa.addArray(100);
	std::cout << "---> FINDING THE SHORTEST/LONGEST SPAN" << std::endl;
		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;
			
}
