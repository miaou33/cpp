#include "WrongCat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

WrongCat::WrongCat () {
	
	_type = "WrongCat"; 
	announce ("constructor");
}

WrongCat::WrongCat (WrongCat const& original) {
	
	*this = original;
	announce ("copy constructor");
}

WrongCat::~WrongCat () {

	announce ("destructor");
}

// OPERATOR = 
WrongCat&	WrongCat::operator= (WrongCat const& toBecome) {

	if (this != &toBecome)
		_type = toBecome.getType ();
	return *this;
}


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	WrongCat::announce (std::string const func) const {

	std::cout << "WrongCat " << func << " called" << std::endl;
}

void	WrongCat::makeSound () const {

	std::cout << "wrong meow" << std::endl;
}