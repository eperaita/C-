/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:20:23 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/23 19:12:41 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"
#include <iomanip>

int main()
{
    size_t i = 0;
    std::string order;
    PhoneBook book;

    while(1)
    {
        std::cout << "-- [ADD] - [SEARCH] - [EXIT] --" << std::endl;
        std::cin >> order;
        if (std::cin.eof())
            break;
        if (!order.compare("ADD"))
        {
            book.add(i);
            if (i == 7)
                i = 0;
            else
                i++;
        }
        else if (!order.compare("SEARCH"))
            book.search();
        else if (!order.compare("EXIT"))
            break;
    }
    return 0;
}
