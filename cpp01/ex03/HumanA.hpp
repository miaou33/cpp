#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA {

	private:
		Weapon		_weapon;
		std::string	_name;

	public:
		HumanA (Weapon weapon);
		void	attack ();

};

#endif