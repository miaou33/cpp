# include "MateriaSource.hpp"

/**************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

MateriaSource::MateriaSource () {

	_nb_learned = 0;
	for (int i = 0; i < _materia_source_max; i++)
		_materia_source [i] = NULL;
}

MateriaSource::MateriaSource (MateriaSource const& original) {

	_nb_learned = 0;
	for (int i = 0; i < _materia_source_max; i++)
	{
		if (original.getMateria (i))
		{
			_materia_source [i] = original.getMateria (i)->clone ();
			_nb_learned++;
		}
	}
}

MateriaSource::~MateriaSource () {

	for (int i = 0; i < _materia_source_max; i++)
	{
		if (_materia_source [i])
			delete (_materia_source [i]);
	}
}

MateriaSource&	MateriaSource::operator= (MateriaSource const& toBecome) {

	if (this != &toBecome)
	{
		_nb_learned = 0;
		for (int i = 0; i < _materia_source_max; i++)
		{
			if (_materia_source [i])
				delete _materia_source [i];
			if (toBecome.getMateria (i))
			{
				_materia_source [i] = toBecome.getMateria(i)->clone ();
				_nb_learned++;
			}
		}
	}
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

AMateria*			MateriaSource::getMateria (int i) const {

	if (is_in_source (i))
		return _materia_source [i];
	return (NULL);
}

/**************************************************************************************/
/*	MEMBER FUNCTIONS																  */
/**************************************************************************************/

bool	MateriaSource::is_in_source (int i) const {

	if (i >= 0 && i < _materia_source_max)
		return true;
	return false;
}

void		MateriaSource::learnMateria (AMateria *m) {

	if (_nb_learned < _materia_source_max)
	{
		int i = 0;
		while (_materia_source [i] && i < _materia_source_max)
			i++;
		_materia_source [i] = m;
		_nb_learned++;
	}
}

AMateria*	MateriaSource::createMateria (std::string const& type) {

	int i = 0;
	while (_materia_source [i] && i < _materia_source_max)
	{
		if (_materia_source [i]->getType () == type)
			return (_materia_source [i]->clone ());
		i++;
	}
	return  (NULL);
}