/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:21:41 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 17:15:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

//Que cojones!!!!!! como voy a hacer un operador sin getter. y como voy a swapear sin acceder a la clase especifica.... 

class Awesome
{
public:
Awesome(void) : _n(0) {}
Awesome( int n ) : _n( n ) {}
Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
int get_n() const { return _n; }
private:
int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }



int main( void ) {
	
	///////// ints ////////
	int a = 2;
	int b = 3;
	std::cout << std::endl;
	std::cout << " INTS" << std::endl;
	std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b); 	
	std::cout << std::endl;
	std::cout << "SWAP -> a = " << a << ", b = " << b << std::endl;
	std::cout << "MIN -> " << ::min( a, b ) << std::endl;
	std::cout << "MAX -> " << ::max( a, b ) << std::endl;
	
	///////// strings ////////

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << std::endl;
	std::cout << " STRINGS" << std::endl;
	std::cout << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << std::endl;
	std::cout << "SWAP -> a = " << a << ", b = " << b << std::endl;
	std::cout << "MIN -> " << ::min( c, d ) << std::endl;
	std::cout << "MAX -> " << ::max( c, d ) << std::endl;
	
	///////// floats ////////
	float e = 0;
	float f = -3.34;
	std::cout << std::endl;
	std::cout << " FLOATS" << std::endl;
	std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(e, f); 	
	std::cout << std::endl;
	std::cout << "SWAP -> a = " << e << ", b = " << f << std::endl;
	std::cout << "MIN -> " << ::min( e, f ) << std::endl;
	std::cout << "MAX -> " << ::max( e, f ) << std::endl;
	
	return 0;
}
