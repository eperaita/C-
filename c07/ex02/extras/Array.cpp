/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:58:30 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/17 23:08:50 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template< typename T>
Array<T> &Array<T>::operator=(Array<T> const &ref)
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
        
template< typename T>
T &Array<T>::operator[](unsigned int pos)
{
            return (this->get_elem(pos));
};

       
template< typename T>
T &Array<T>::get_elem(unsigned int pos) const
{
            if (this->size < pos)
            {
                throw Array::Access();
            }
            return (this->elem[pos]);
};

template< typename T>
void Array<T>::fill_elem(unsigned int pos, T const &fill)
{
            this->elem[pos] = fill;
};

template< typename T>
unsigned int Array<T>::get_size() const{ return (this->size); };
