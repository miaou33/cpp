#include "Animal.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Animal::Animal () : _type ("Animal") {

	announce ("constructor");
}

Animal::Animal (Animal const& original) {

	*this = original;
	announce ("copy constructor");
}

Animal::~Animal () {

	announce ("destructor");
}

// OPERATOR=
Animal&	Animal::operator= (Animal const& rhs) {

	if (this != &rhs)
		_type = rhs.getType ();
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	Animal::getType () const { return _type; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Animal::announce (std::string const func) const {

	std::cout << "Animal " << func << " called" << std::endl;
}

void	Animal::makeSound () const {

	std::cout << "anon animal sound" << std::endl;
}