#include "Cat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Cat::Cat () {	_type = "Cat"; 
				_brain = new Brain ();

	announce ("Cat", "constructor");
}

Cat::Cat (Cat const& original) {
	
	*this = original;
	announce ("Cat", "copy constructor");
}

Cat::~Cat () {

	delete _brain;
	announce ("Cat", "destructor");
}

// OPERATOR = 
Cat&	Cat::operator= (Cat const& source) {

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

Brain*	Cat::getBrain () const { return _brain; }