#include "Dog.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Dog::Dog () {  _type = "Dog";
	
	announce ("Dog", "constructor");
}

Dog::Dog (Dog const& original) { _type = original.getType (); 

	announce ("Dog", "copy constructor");
}

Dog::~Dog () {

	announce ("Dog", "destructor");
}

// OPERATOR =
Dog&	Dog::operator= (Dog const& source) {

	if (this != &source)
		_type = source.getType ();
	return (*this);
}
