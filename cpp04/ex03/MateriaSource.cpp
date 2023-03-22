# include "MateriaSource.hpp"

/**************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

MateriaSource::MateriaSource () {}

MateriaSource::MateriaSource (MateriaSource const& original) {}

MateriaSource&	MateriaSource::operator= (MateriaSource const& source) {}

MateriaSource::~MateriaSource () {}

/**************************************************************************************/
/*	MEMBER FUNCTIONS																  */
/**************************************************************************************/

void		MateriaSource::learnMateria (AMateria *m) {}

AMateria*	MateriaSource::createMateria (std::string const& type) {}