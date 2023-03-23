# include "Ice.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Ice::Ice () : AMateria ("ice") {}

Ice::Ice (std::string const& type) : AMateria (type) {}

Ice::Ice (Ice const& original) : AMateria (original) {}

Ice::~Ice () {}

Ice& Ice::operator= (Ice const& toBecome) {

	if (this != &toBecome)
		_type = toBecome.getType ();
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const& Ice::getType () const {

	return (std::string const&) _type;
}

/******************************************************************************************************/
/*	MEMBER FUNCTIONS																				  */
/******************************************************************************************************/

Ice*	Ice::clone () const {

	return new Ice (*this);
}

void	Ice::use (ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName () << " *" << std::endl;
}