#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon {

	private:
		std::string	_type;

	public:
		/* CONSTRUCTOR & DESTRUCTOR */
		Weapon ();
		Weapon (std::string type);

		/* METHODS */
		std::string const	&getType (void) const;
		void				setType (std::string type);

};

#endif