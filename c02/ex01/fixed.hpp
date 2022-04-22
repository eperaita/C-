/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:20:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/25 17:15:40 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;
};
		
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);
		

#endif
