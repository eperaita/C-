/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:20:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 12:20:00 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
		int _fixed_point_value;
		static int const _bits; 
	public:
		Fixed(void);
		Fixed(int const input);
		Fixed(float const input);
		~Fixed(void);
		Fixed(Fixed const &fixed);


		Fixed &operator=(Fixed const &fixed);
	
		//operadores de comparación 	
		bool operator<(Fixed const &fixed) const;
		bool operator>(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		
		//operadores + - * /  
		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;
		
		//operadores de pre/post incremento/decremento
		Fixed operator++(int);	//i++
		Fixed &operator++(void); //++i
		Fixed operator--(int);	//i--
		Fixed &operator--(void);	//--i
		
		//min y max 
		static Fixed const &min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed const &max(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;
};
		
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);
		

#endif
