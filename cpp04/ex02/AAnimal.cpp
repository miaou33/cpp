#include "AAnimal.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

AAnimal::AAnimal () : _type ("AAnimal") {

	announce ("constructor");
}

AAnimal::AAnimal (AAnimal const & original) {

	*this = original;
	announce ("copy constructor");
}

AAnimal::~AAnimal () {

	announce ("destructor");
}

// OPERATOR=
AAnimal&	AAnimal::operator= (AAnimal const & source) {

	if (this != &source)
		_type = source.getType ();
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	AAnimal::getType () const { return _type; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	AAnimal::announce (std::string const func) const {

	std::cout << "AAnimal " << func << " called" << std::endl;
}

void	AAnimal::makeSound () const {

	std::cout << "anon AAnimal sound" << std::endl;
}