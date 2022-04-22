/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:25:09 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 02:11:44 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// call to functions :
	//Independent functions in header: defined as template. -> ::swap( a, b ) 
	//Inside a Class ->  Class::swap( a, b )

//	MUST define  template<typename T> above each function, not only once (it doesent recognize T type)

template< typename T>
void swap(T &x, T &y){
	
	T temp = x;
	x = y;
	y = temp;
}

template< typename T>
T const & max(T const & x, T const & y){
	return ( (x>y) ? x : y);
}

template< typename T>
T const & min(T const & x, T const & y){
	return ( (x<y) ? x : y);
}
