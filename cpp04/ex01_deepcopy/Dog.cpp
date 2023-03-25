#include "Dog.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Dog::Dog () {
	
	_type = "Dog"; 
	_brain = new Brain ();
	announce ("constructor");
}

Dog::Dog (Dog const& original) : Animal (original) {
	
	_brain = new Brain (*(original.getBrain ()));
	announce ("copy constructor");
}

Dog::~Dog () {

	delete _brain;
	announce ("destructor");
}

// OPERATOR = 
Dog&			Dog::operator= (Dog const& rhs) {

	if (this != &rhs)
	{
		_type = rhs.getType ();
		(*_brain) = *(rhs.getBrain ());
	}
	announce ("assignment operator");
	return *this;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Brain*			Dog::getBrain () const { 
	
	return _brain;
}

std::string		Dog::getIdea (int i) const {
	
	return _brain->getIdea (i);
}

void			Dog::setIdea (int i, std::string idea) {

	_brain->setIdea (i, idea);
}

void			Dog::displayIdea (int i) const {

	_brain->displayIdea (i);
}


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void			Dog::announce (std::string const func) const {

	std::cout << "Dog " << func << " called" << std::endl;
}

void			Dog::makeSound () const {

	std::cout << "bark" << std::endl;
}