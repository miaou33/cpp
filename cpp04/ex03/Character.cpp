#include "Character.hpp"

/**************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

Character::Character (std::string name) : _name (name) {}

Character::Character (Character const& original) : _name (original.getName ()) {

	_materias = new AMateria* [4];
}

Character::~Character () {}

Character& Character::operator= (Character const& source) {

	if (this != &source)
	{
		_name = source.getName ();
/* 		for (int i = 0; *_materias != NULL && i < 4; i++)
			delete *_materias;
		for (int i = 0; *(source.) */
	}
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const&	Character::getName () const {

	return (std::string const&) _name;
}

/**************************************************************************************/
/*	MEMBER FUNCTIONS																  */
/**************************************************************************************/

void	Character::equip (AMateria* m) {

/* 	for (int i = 0; i < 4; i++)
	{
		if (*_materias == NULL)
		{
			*_materias = new AMateria (m);
		} */
	}
}

void	Character::unequip (int idx) {}

void	Character::use (int idx, ICharacter& target) {}
