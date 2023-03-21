# include "Ice.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Ice::Ice (std::string const& type) : AMateria (type) {}

Ice::Ice (Ice const& original) : AMateria (original) {}

Ice::~Ice () {}

Ice& Ice::operator= (Ice const& source) {

	if (this != &source)
		_type = source.getType ();
	return *this;
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