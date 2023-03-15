#include "Cat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Cat::Cat () {
	
	_type = "Cat"; 
	announce ("constructor");
}

Cat::Cat (Cat const & original) {
	
	*this = original;
	announce ("copy constructor");
}

Cat::~Cat () {

	announce ("destructor");
}

// OPERATOR = 
Cat&	Cat::operator= (Cat const & source) {

	if (this != &source)
		_type = source.getType ();
	return *this;
}


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Cat::announce (std::string const func) const {

	std::cout << "Cat " << func << " called" << std::endl;
}

void	Cat::makeSound () const {

	std::cout << "meow" << std::endl;
}