#include "Character.hpp"

/**************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

Character::Character (std::string name) : _name (name) {
	
	_nb_equiped = 0;
	for (int i = 0; i < _bag_max; i++)
		_bag [i] = NULL;
}

Character::Character (Character const& original) : _name (original.getName ()) {

	_nb_equiped = 0;
	for (int i = 0; i < _bag_max; i++)
	{
		if (original.getMateria (i))
		{
			_bag [i] = original.getMateria (i)->clone ();
			_nb_equiped ++;
		}
	}
}

Character::~Character () {

	for (int i = 0; i < _bag_max; i++)
	{
		if (_bag [i])
			delete _bag [i];
	}
}

Character& Character::operator= (Character const& toBecome) {

	if (this != &toBecome)
	{
		_name = toBecome.getName ();
		_nb_equiped = 0;
		for (int i = 0; i < _bag_max; i++)
		{
			if (_bag[i])
				delete _bag [i];
			if (toBecome.getMateria (i))
			{
				_bag [i] = toBecome.getMateria(i)->clone();
				_nb_equiped++;
			}
		}
	}
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const&	Character::getName () const {

	return (std::string const&) _name;
}

AMateria*			Character::getMateria (int i) const {

	if (is_in_bag (i))
		return _bag [i];
	return (NULL);
}

/**************************************************************************************/
/*	MEMBER FUNCTIONS																  */
/**************************************************************************************/

bool	Character::is_in_bag (int i) const {

	if (i >= 0 && i < _bag_max)
		return true;
	return false;
}

void	Character::equip (AMateria* m) {

	if (m && _nb_equiped < _bag_max)
	{
		int i = 0;
		while (_bag [i] && i < _bag_max)
			i++;
		_bag [i] = m;
		_nb_equiped++;
		std::cout << _name << " equiped " << m->getType ()
					<< "\n\t-> number of materias in bag = " << _nb_equiped << std::endl;
	}
}

void	Character::unequip (int idx) {

	if (is_in_bag (idx) && _bag [idx])
	{
		_bag [idx] = NULL;
		_nb_equiped--;
	}
}

void	Character::use (int idx, ICharacter& target) {

	if (is_in_bag (idx) && _bag [idx])
		_bag [idx]->use (target);
}

