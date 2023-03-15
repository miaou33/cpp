#include "Cat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Cat::Cat () {	_type = "Cat"; 
				_brain = new Brain ();

	announce ("constructor");
}

Cat::Cat (Cat const & original) {
	
	*this = original;
	announce ("copy constructor");
}

Cat::~Cat () {

	delete _brain;
	announce ("destructor");
}

// OPERATOR = 
Cat&	Cat::operator= (Cat const & source) {

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

std::string	Cat::getType () const { return _type; }

Brain*	Cat::getBrain () const { return _brain; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Cat::announce (std::string const func) const {

	std::cout << "Cat " << func << " called" << std::endl;
}

void	Cat::makeSound () const {

	std::cout << "meow" << std::endl;
}