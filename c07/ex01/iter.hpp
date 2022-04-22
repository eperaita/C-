/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:25:09 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/14 23:49:36 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

///////////// ITER //////////////

template< typename T>
void iter(T *array, int size, T f(T &elem)){

	int i;

	i = -1;
	while (++i < size)
		array[i] = f(array[i]);
}


///////// EXTRA FUNCTIONS TO USE ON ITER //////////


template< typename T>
T squared(T &x){

	return ( x * x);
}

template< typename T>
T cubed(T &x){
	return ( x * x * x);
}

template< typename T>
T print(T &print){

	std::cout << print << "  " << std::endl;
	return (print);

}


