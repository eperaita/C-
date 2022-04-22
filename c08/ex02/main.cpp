/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:35:42 by eperaita          #+#    #+#             */
/*   Updated: 2022/04/18 19:42:13 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>

int main()
{

	//////              MUTANTSTACK           //////
    std::cout << "->    MUTANTSTACK " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	//std::cout << mstack.top() << std::endl;
	mstack.pop();
	//std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);



	//////              EMULATION WITH LIST           //////
    std::cout << "->    EMULATION WITH LIST " << std::endl;

	std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();//elimino el ultimo, no el primero. Stack almacena al reves. 
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);


    std::list<int>::iterator it_lst;
    std::list<int>::iterator ite_lst;
    it_lst = lst.begin();
    ite_lst = lst.end();
    while (it_lst != ite_lst)
    {
        std::cout << *it_lst << std::endl;
        ++it_lst;
    }


	 //////              MUTANTSTACK STRING           //////
    std::cout << "->    MUTANTSTACK STRING " << std::endl;
    MutantStack<std::string> strstack;
    strstack.push("fghjk");
    strstack.push("dfghjk");
    strstack.pop();
    strstack.push("klfghjkl");
    strstack.push("rydc");
    strstack.push("oyigjch");
    strstack.push("aaaaakl");
    strstack.push("ghj865l");
    strstack.push("uyoi");
    strstack.push("awqeq");


    MutantStack<std::string>::iterator s_it = strstack.begin();
    MutantStack<std::string>::iterator s_ite = strstack.end();
    ++s_it;
    --s_it;
    while (s_it != s_ite)
    {
        std::cout << *s_it << std::endl;
        ++s_it;
    }

	return 0;
}
