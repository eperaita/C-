/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:20:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 17:14:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
	private:
		int _value;
		static int const _rawBits; 
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &fixed);

		Fixed &operator=(Fixed const &fixed);

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		//por que se llaman getrawbits/setrawbits si lo que devuelven es value??
};
#endif
