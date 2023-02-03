#include "Weapon.hpp"

Weapon::Weapon () {}

Weapon::Weapon	(std::string type) {
	_type = type;
}

std::string	const &Weapon::getType (void) const
{
	std::string	const &typeREF = _type;
	return (typeREF);
}

void	Weapon::setType (std::string type)
{
	_type = type;
}