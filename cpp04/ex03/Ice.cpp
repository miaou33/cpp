# include "Ice.hpp"

/******************************************************************************************************/
/*									CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/******************************************************************************************************/

Ice::Ice (std::string const & type) : _type (type) {}

Ice::Ice (Ice const & original) : _type (original.getType ()) {}

Ice::~Ice () {}

Ice& Ice::operator = (Ice const & source) {

	if (&source == this)
		return *this;
 	this->~Ice ();
	new (this) Ice (source);
	return *this;
}


/******************************************************************************************************/
/*												GETTERS SETTERS														  */
/******************************************************************************************************/

std::string const &	Ice::getType () const {

	return _type;
}


/******************************************************************************************************/
/*												MEMBER FUNCTIONS													  */
/******************************************************************************************************/

Ice *	Ice::clone () const {

	return new Ice (*this);
}

void	Ice::use (ICharacter & target) {

	std::cout << "* shoots an ice bolt at " << target.getName () << " *" << std::endl;
}