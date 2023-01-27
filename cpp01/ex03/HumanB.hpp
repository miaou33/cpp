#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {

	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB (std::string name);
		void	setWeapon (Weapon &weapon); // receives a REF so when the obj is sent in param, it is received with its address
		void	attack ();
};

#endif