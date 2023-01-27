#include "Weapon.hpp"

Weapon::Weapon () {}

Weapon::Weapon	(std::string type) {
	_type = type;
}

const std::string	&Weapon::getType (void)
{
	const std::string	&typeREF = _type;
	return (typeREF);
}

void	Weapon::setType (std::string type)
{
	_type = type;
}