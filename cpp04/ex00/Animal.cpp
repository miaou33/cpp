#include "Animal.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Animal::Animal () : _type ("Animal") {

	announce (*this, "constructor");
}

Animal::Animal (Animal const& original) : _type (original.getType ()) {

	announce (*this, "copy constructor");
}

Animal::~Animal () {

	announce (*this, "destructor");
}

// OPERATOR=
Animal&	Animal::operator= (Animal const& source) {

	if (this != &source)
		_type = source.getType ();
	return (*this);
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	Animal::getType () const { return _type; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Animal::announce (Animal const &animal, std::string announceType) const {

	std::cout << animal.getType () << " " << announceType << " called" << std::endl;
}