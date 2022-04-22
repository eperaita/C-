/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:21:41 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/17 23:00:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#define MAX_VAL 750

template< typename T>
void random(Array<T> &a, int check)
{
    unsigned int i;
	T temp;

    srand (time(NULL));
    i = 0;
    while (check == 0 && a.get_size() > i)
	{
		temp = static_cast<T>(rand()) / static_cast<T>(10000000) ;
	   	//( rand() % 100 does not work with floats), division to accurate the range of the random numbers
		a.fill_elem(i, temp);
		i++;
	}
    while (check == 1 && a.get_size() > i)
	{
		temp = static_cast<T>(rand() % 126 + 32) ;
		a.fill_elem(i, temp);
		i++;
	}
};

template< typename T>
void random_str(Array<T> &a)
{
    unsigned int i;
    unsigned int size;
	std::string base = "abcdefghijklmnopqrstuvwxyz";
	T temp;

	size = 0;
	i = 0;
    while (a.get_size() > i)
	{
		size = 8;
		while (size--)
    		temp += static_cast<char>(base[(rand() % base.size())]);
		a.fill_elem(i, temp);
		temp = "";
    	i++;
	}
};

int main(int, char**)
{
	//////////////////////////SUBJECT MAIN//////////////////////////
	std::cout << std::endl <<"___SUBJECT MAIN____" << std::endl << std::endl;
    
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	
	/////////////////////////////OWN MAIN//////////////////////////////////////
	std::cout << std::endl <<"____OWN MAIN____" << std::endl << std::endl;
	
	std::cout << std::endl;
	std::cout <<"--->  INTS" << std::endl << std::endl;
	std::cout << std::endl;
	std::cout <<"      <EMPTY ARRAY>" << std::endl << std::endl;
	Array<int> empty; //Array default (empty)
	std::cout << empty << std::endl;
	
	std::cout <<"      <PARAMETER ARRAY>" << std::endl << std::endl;
	Array<int> num(33); //Array of <int>
	random<int>(num, 0); //Fill array (random())
	std::cout << num << std::endl; 	

	std::cout <<"       <COPY ARRAY>" << std::endl << std::endl;
	Array<int> copy;
	copy = num; //Copy Array num	
	std::cout << copy << std::endl; 

	std::cout <<"       <ACCESS AN ELEMENT and SIZE>" << std::endl << std::endl;
	unsigned int i = 5;
	try
	{
		std::cout << "Content of [" << i << "] ----> " << num[i] << std::endl; // [] operator
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	i = -2;
	try
    {
        std::cout << "Content of [position out of range] ----> " << num[i] << std::endl; // [] operator
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }	
	std::cout << "Size of the array ----> " << num.get_size() << std::endl; 
	
	
	std::cout << std::endl;
	std::cout <<"--->  FLOATS" << std::endl << std::endl;
	Array<float> f(7); //Array of <float>
	random<float>(f, 0); 
	std::cout << f << std::endl; 

	
	std::cout << std::endl;
	std::cout << "-->  CHARS" << std::endl << std::endl;
	Array<char> c(5); //Array of <char>
	random<char>(c, 1); 
	std::cout << c << std::endl; 

	
	std::cout << std::endl;
	std::cout <<"--->  STRINGS " << std::endl << std::endl;
	Array<std::string> str(5); //Array of <string>
	random_str<std::string>(str); 
	std::cout << str << std::endl; 

	return 0;
}
	



/*Tip: try to compile int * a = new int();, then display *a.
	int *a= new int();
	int *b= new int(5);

	std::cout <<" new int a() = " << *a << std::endl;
	std::cout <<" new int(5) = " << *b << std::endl;*/
