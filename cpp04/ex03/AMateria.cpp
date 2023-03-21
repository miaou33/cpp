# include "AMateria.hpp"

/**************************************************************************************/
/*					CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**************************************************************************************/

AMateria::AMateria (std::string const & type) : _type (type) {}

AMateria::AMateria (AMateria const & original) : _type (original.getType ()) {}

AMateria::~AMateria () {}

AMateria& AMateria::operator = (AMateria const & source) {

	if (&source == this)
		return *this;
 	this->~AMateria ();
	new (this) AMateria (source);
	return *this;
/* 	if (this != &source)
		_type = source.getType ();
	return *this; */
}


/**************************************************************************************/
/*								GETTERS SETTERS														  */
/**************************************************************************************/

std::string const & AMateria::getType () const {

	return (std::string const &) _type;
}


/**************************************************************************************/
/*								MEMBER FUNCTIONS													  */
/**************************************************************************************/

/* void	AMateria::use (ICharacter & target) {

	std::cout << "using " << target << std::endl;
} */