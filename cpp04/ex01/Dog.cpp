#include "Dog.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Dog::Dog () {	_type = "Dog";
				_brain = new Brain ();

	announce ("Dog", "constructor");
}

Dog::Dog (Dog const& original) {
	
	*this = original;
	announce ("Dog", "copy constructor");
}

Dog::~Dog () {

	delete _brain;
	announce ("Dog", "destructor");
}

// OPERATOR =
Dog&	Dog::operator= (Dog const& source) {

	if (this != &source)
	{
		_type = source.getType ();
		_brain = new Brain ();
		_brain = source.getBrain ();
	}
	return *this;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Brain*	Dog::getBrain () const { return _brain; }