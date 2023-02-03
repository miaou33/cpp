/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:45:06 by nfauconn          #+#    #+#             */
/*   Updated: 2023/02/03 16:28:47 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) {}

Zombie::Zombie (std::string name) : _name(name) {}

Zombie::~Zombie (void) {
	std::cout << _name << " destroyed" << std::endl;
}
void	Zombie::announce (void) {
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::addName (std::string name) {
	_name = name;
}