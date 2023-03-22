# include "Cure.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Cure::Cure () : AMateria ("Cure") {}

Cure::Cure (std::string const& type) : AMateria (type) {}

Cure::Cure (Cure const& original) : AMateria (original) {}

Cure::~Cure () {}

Cure& Cure::operator= (Cure const& toBecome) {

	if (this != &toBecome)
		_type = toBecome.getType ();
	return *this;
}

/**************************************************************************************/
/*	GETTERS SETTERS																	  */
/**************************************************************************************/

std::string const& Cure::getType () const {

	return (std::string const&) _type;
}

/******************************************************************************************************/
/*	MEMBER FUNCTIONS																				  */
/******************************************************************************************************/

Cure*	Cure::clone () const {

	return new Cure (*this);
}

void	Cure::use (ICharacter& target) {

	std::cout << "* heals " << target.getName () << "'s wounds *" << std::endl;
}