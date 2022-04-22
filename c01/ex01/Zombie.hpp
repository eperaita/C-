/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:12:48 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 17:19:54 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string z_name;
		void announce(void);
	public:
		Zombie(void);//Contructor??
		~Zombie(void);//Destructor??
		Zombie* zombieHorde(int N, std::string name);
		Zombie* newZombie(std::string name);
};



# endif
