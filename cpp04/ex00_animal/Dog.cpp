#include "Dog.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Dog::Dog () {	_type = "Dog";

	announce ("constructor");
}

Dog::Dog (Dog const& original) {
	
	*this = original;
	announce ("copy constructor");
}

Dog::~Dog () {

	announce ("destructor");
}

// OPERATOR =
Dog&	Dog::operator= (Dog const& source) {

	if (this != &source)
		_type = source.getType ();
	return *this;
}


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Dog::announce (std::string const func) const {

	std::cout << "Dog " << func << " called" << std::endl;
}

void	Dog::makeSound () const {

	std::cout << "waf" << std::endl;
}