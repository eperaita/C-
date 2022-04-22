/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:31:10 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 19:31:14 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <iostream>
#include  <climits> 

Span::Span(): size(){};

Span::Span(unsigned int n): size(n){};

Span::~Span(){};

void Span::addNumber(int num)
{
	try
	{
		if (this->array.size() < this->size)
		{
			this->array.push_back(num);
			std::cout << "filled [" << this->array.size() - 1 << "] -> " << num << std::endl;
		}
		else
			throw Span::NoPlace();
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

};

void Span::addArray(unsigned int size)
{
	//unsigned int i = 0;
	int random;
	srand (time(NULL));
	while (this->array.size() < size)
	{
		random = rand() % INT_MAX;
		this->array.push_back(random);
		//std::cout << "filled [" << i++ << "] -> "<< random << std::endl;
	}	
}



int Span::longestSpan(){

	unsigned int min;
	unsigned int max;
	if(this->array.size() > 1)
	{
		max = *(std::max_element(this->array.begin(), this->array.end()));
		min = *(std::min_element(this->array.begin(), this->array.end()));
		return (max - min);

	}
	else
		throw Span::NoSpan();

};

int Span::shortestSpan(){

	if(this->array.size())
	{
		int shortest = INT_MAX;
		unsigned int i = 0;
		while (i < this->array.size())
		{
			unsigned int j = i + 1;
			while (j < this->array.size())
			{
				//std::cout << "comprobacion: array[" << i << "] y [" << j << "] : " << array[i] << " y " << array[j] << " = " << this->array[i] - this->array[j] << std::endl;
				if ((std::abs(this->array[i] - this->array[j])) < shortest)
				{
					shortest = std::abs(this->array[i] - this->array[j]);
					//std::cout << "shortest = " << shortest << std::endl;
				}
				j++;
			}
			i++;
		
		}

		return (std::abs(shortest));
	}
	else
		throw Span::NoSpan();


};
