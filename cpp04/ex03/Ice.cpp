# include "Ice.hpp"

/******************************************************************************************************/
/*									CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR										  */
/******************************************************************************************************/

Ice::Ice (std::string const & type) : _type (type) {}

Ice::Ice (Ice const & original) : _type (original.getType ()) {}

Ice::~Ice () {}

Ice& Ice::operator = (Ice const & source) {

	if (this != &source)
		_type = source.getType ();
	return *this;
}


/******************************************************************************************************/
/*												GETTERS SETTERS														  */
/******************************************************************************************************/

std::string const &	Ice::getType () const {

	return (std::string const &) _type;
}


/******************************************************************************************************/
/*												MEMBER FUNCTIONS													  */
/******************************************************************************************************/

Ice *	Ice::clone () const {

	return new Ice (*this);
}

/* void	Ice::use (ICharacter & target) {

} */