#include "Dog.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Dog::Dog () {	_type = "Dog";
				_brain = new Brain ();

	announce ("constructor");
}

Dog::Dog (Dog const& original) {
	
	*this = original;
	announce ("copy constructor");
}

Dog::~Dog () {

	delete _brain;
	announce ("destructor");
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


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Dog::announce (std::string const func) const {

	std::cout << "Dog " << func << " called" << std::endl;
}

void	Dog::makeSound () const {

	std::cout << "waf" << std::endl;
}