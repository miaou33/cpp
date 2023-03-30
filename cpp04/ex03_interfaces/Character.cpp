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
		else
			_bag [i] = NULL;
	}
}

Character::~Character () {

	for (int i = 0; i < _bag_max; i++)
	{
		if (_bag [i])
			delete _bag [i];
	}
}

Character& Character::operator= (Character const& rhs) {

	if (this != &rhs)
	{
		_name = rhs.getName ();
		_nb_equiped = 0;
		for (int i = 0; i < _bag_max; i++)
		{
			if (_bag[i])
				delete _bag [i];
			if (rhs.getMateria (i))
			{
				_bag [i] = rhs.getMateria(i)->clone();
				_nb_equiped++;
			}
			else
				_bag [i] = NULL;
		}
	}
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const&	Character::getName () const {

	return _name;
}

AMateria*			Character::getMateria (int i) const {

	if (is_in_bag (i))
		return _bag [i];
	return (NULL);
}

/**************************************************************************************/
/*	OTHER MB FUNCTIONS																  */
/**************************************************************************************/

bool	Character::is_in_bag (int i) const {

	if (i >= 0 && i < _bag_max)
		return true;
	return false;
}

void	Character::equip (AMateria* m) {

	if (!m || _nb_equiped >= _bag_max)
	{
		!m ?
			std::cout << "Error: null ptr" << std::endl
			: std::cout << _name << " cannot equip more materias. Bag full" << std::endl;
		return ;
	}

	int i = 0;
	
	while (_bag [i] && i < _bag_max)
		i++;
	_bag [i] = m;
	_nb_equiped++;
	std::cout << _name << " equiped " << m->getType ()
				<< "\n\t-> number of materias in bag = " << _nb_equiped << std::endl;
}

void	Character::unequip (int idx) {

	std::string	type;

	if (is_in_bag (idx) && _bag [idx])
	{
		type = _bag [idx] -> getType ();
		_bag [idx] = NULL;
		_nb_equiped--;
		std::cout << _name << " unequiped " << type
					<< "\n\t-> number of materias in bag = " << _nb_equiped << std::endl;
	}
}

void	Character::use (int idx, ICharacter& target) {

	if (is_in_bag (idx) && _bag [idx])
		_bag [idx]->use (target);
}

