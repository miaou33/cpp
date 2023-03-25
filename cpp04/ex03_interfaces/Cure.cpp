# include "Cure.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Cure::Cure () : AMateria ("cure") {}

Cure::Cure (std::string const& type) : AMateria (type) {}

Cure::Cure (Cure const& original) : AMateria (original) {}

Cure::~Cure () {}

Cure& Cure::operator= (Cure const& rhs) {

	if (this != &rhs)
		_type = rhs.getType ();
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const& Cure::getType () const {

	return (std::string const&) _type;
}

/******************************************************************************************************/
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/

Cure*	Cure::clone () const {

	return new Cure (*this);
}

void	Cure::use (ICharacter& target) {

	std::cout << "* heals " << target.getName () << "'s wounds *" << std::endl;
}