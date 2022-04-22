/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:33:16 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/07 19:42:32 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class Contact{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string darkest_secret;
	std::string check_lenhth(std::string str);
    public:
        Contact(void);//Constructor
		void set_contact(std::string na, std::string l, std::string ni, std::string p, std::string d);
		void get_list(int i);
		void get_contact(void);
};

class PhoneBook{
    private:
	int filled;
    Contact c[8];

    public:
		PhoneBook(void);//Constructor
		~PhoneBook(void);//Destructor
        void add(int i);
		void search(void);

};

#endif
