#include "Cat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Cat::Cat () { _type = "Cat"; 

	announce ("Cat", "constructor");
}

Cat::Cat (Cat const& original) { _type = original.getType ();

	announce ("Cat", "copy constructor");
}

Cat::~Cat () {

	announce ("Cat", "destructor");
}

// OPERATOR = 
Cat&	Cat::operator= (Cat const& source) {

	if (this != &source)
		_type = source.getType ();
	return (*this);
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

