/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:44:25 by nfauconn          #+#    #+#             */
/*   Updated: 2023/02/03 16:52:03 by nfauconn         ###   ########.fr       */
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
		Zombie (std::string name);
		~Zombie (void);

		void	announce (void) const;
};

void	randomChump (std::string name);
Zombie	*newZombie (std::string name);

#endif