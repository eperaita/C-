/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:53:54 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/08 13:16:23 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	char ch;
	size_t i;
	size_t j;
	
	if(argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';	
	   return 1;	
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while(argv[i][++j])
		{
			ch = std::toupper(argv[i][j]);
			std::cout << ch;
		}
	}
	std::cout << std::endl;
	return 0;
}
