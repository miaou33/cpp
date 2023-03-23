# include "AMateria.hpp"

/**************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

AMateria::AMateria (std::string const& type) : _type (type) {}

AMateria::AMateria (AMateria const& original) : _type (original.getType ()) {}

AMateria::~AMateria () {}

AMateria& AMateria::operator= (AMateria const& toBecome) {

	if (this != &toBecome)
		_type = toBecome.getType ();
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const& AMateria::getType () const {

	return (std::string const&) _type;
}

/**************************************************************************************/
/*	MEMBER FUNCTIONS																  */
/**************************************************************************************/

void	AMateria::use (ICharacter& target) {

	std::cout << "* throw a random material at " << target.getName () << " *" << std::endl;
}