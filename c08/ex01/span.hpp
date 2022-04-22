/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:31:15 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 19:30:48 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP


#include <vector>

class Span
{
	private:
		std::vector<int> array;
		unsigned int size;
	public: 
		Span();
		Span(unsigned int n);
		~Span();

		void addNumber(int num);
		void addArray(unsigned int size);
		int shortestSpan();
		int longestSpan();

		class NoPlace : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("> No place in the container");
            };
        };
		class NoSpan : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("> No span to find");
            };
		};

};

#endif
