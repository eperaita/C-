/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:42:25 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 20:01:37 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <algorithm>

class NoOccurrence : public std::exception
{
	virtual const char* what() const throw()
	{
    	return ("> No Occurrence in the container");
	};
};

//Must return an iterator because to print the content must be an iterator of a specific type and be defined????
template< typename T>
typename T::iterator easyfind(T &cont, int x){

	if ( (std::find(cont.begin(), cont.end(), x)) != cont.end())
		return (std::find(cont.begin(), cont.end(), x));
	throw NoOccurrence ();
	
};
	
	
	
