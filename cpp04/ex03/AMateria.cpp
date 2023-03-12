# include "AMateria.hpp"

/**********************************************************************************************************************/
/*									CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/**********************************************************************************************************************/

AMateria::AMateria (std::string const & type) : _type (type) {}

AMateria::AMateria (AMateria const & original) {

	*this = original;
}

AMateria::~AMateria () {}

AMateria& AMateria::operator = (AMateria const & source) {

	if (this != &source)
	{
		_type = (std::string) source.getType ();
	}
	return *this;
}


/**********************************************************************************************************************/
/*												GETTERS SETTERS														  */
/**********************************************************************************************************************/

std::string const &	AMateria::getType () const {

	return (std::string const&) _type;
}


/**********************************************************************************************************************/
/*												MEMBER FUNCTIONS													  */
/**********************************************************************************************************************/

/* void	AMateria::use (ICharacter & target) {

} */