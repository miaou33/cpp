/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:44:25 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/26 18:53:56 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie {

	private:
		std::string	_name;

	public:
	 	Zombie (void);
		Zombie (std::string name);
		~Zombie (void);

		void	announce (void);
		void	addName (std::string name);
};

Zombie	*zombieHorde (int N, std::string name);

#endif