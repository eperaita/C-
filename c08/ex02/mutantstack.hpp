/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:35:39 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 19:42:15 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack(MutantStack<T> const &copy){return (std::stack<T>(copy));};
		virtual ~MutantStack(){};
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;


		iterator begin(){ return (this->c.begin());};
        iterator end(){ return (this->c.end());};
        const_iterator begin() const{ return (this->c.begin());};
        const_iterator end() const{ return (this->c.end());};

};


#endif
