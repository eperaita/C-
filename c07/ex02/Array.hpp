/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:25:09 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/17 23:12:29 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdexcept>
#include <iostream>

#ifndef ARRAY_HPP
#define ARRAY_HPP

template< typename T>
class Array{

	private:
		T *elem;
		unsigned int size;
	public:
		Array() : elem(NULL), size(0){};
		Array(unsigned int n) : elem(new T[n]), size(n){}; 
		Array(Array &ref) : elem(NULL), size(0) { *this = ref; };	
		~Array(){ delete[] elem; };


		/*Array<T> &operator=(Array<T> const &ref);
		T &operator[](unsigned int pos);
		T &get_elem(unsigned int pos) const;
		void fill_elem(unsigned int pos, T const &fill);
		unsigned int get_size() const;*/


		Array<T> &operator=(Array<T> const &ref)
		{
			unsigned int i ;

			this->size = ref.get_size();
    		this->elem = new T[this->size];
    		i = 0;
    		while(i < this->size)
			{
				this->fill_elem(i, ref.get_elem(i));
				i++;
			}
    		return (*this);
		};
		T &operator[](unsigned int pos)
		{
			return (this->get_elem(pos));
		};

		T &get_elem(unsigned int pos) const
		{
   			if (this->size < pos)
			{
				throw Array::Access();
			}
    		return (this->elem[pos]);
		};
		void fill_elem(unsigned int pos, T const &fill)
		{
			this->elem[pos] = fill;
		};
		unsigned int get_size() const{ return (this->size); };

		class Access : public std::exception
        {
            virtual const char* what() const throw()
			{
    			return ("> Bad memory access");
			};
        };
};

template< typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &print)
{
	unsigned int i;

	i = 0;
	out <<  "Array -> " ;
	while(i < print.get_size())
		out << "["<< print.get_elem(i++) << "] ";
	out <<  std::endl;
	return (out);
};

#endif

//I tried to write a .cpp with the definitions of the functions, but being a template<> function, must write them in .h.
//INCLUDE !!!!!!!
//If I define them in .cpp doesent recognize <T> parameter, and if I add template< typename T> for each funcion it doesent recognize the Array class. 
