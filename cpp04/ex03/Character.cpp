#include "Character.hpp"

Character::Character (std::string name) {

	_name = name;
}

Character::Character (Character const & original) {

	_name = original.getName ();
}

Character::~Character () {}

Character& Character::operator= (Character const & source) {

	if (this != &source)
		_name = source.getName ();
	return *this;
}

std::string const &	Character::getName () const {

	return (std::string const &) _name;
}

void	Character::equip (AMateria* m) {}

void	Character::unequip (int idx) {}

void	Character::use (int idx, ICharacter& target) {}
