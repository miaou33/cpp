#include "Animal.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Animal::Animal () : _type ("Animal") {

	announce ("Animal", "constructor");
}

Animal::Animal (Animal const& original) : _type (original.getType ()) {

	announce ("Animal", "copy constructor");
}

Animal::~Animal () {

	announce ("Animal", "destructor");
}

// OPERATOR=
Animal&	Animal::operator= (Animal const& source) {

	if (this != &source)
		_type = source.getType ();
	return (*this);
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	Animal::getType () const { return _type; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Animal::announce (std::string const who, std::string const what) const {

	std::cout << who << " " << what << " called" << std::endl;
}

void	Animal::makeSound () {

	std::string	sound;

	if (_type == "Dog")
		sound = "waf";
	else if (_type == "Cat")
		sound = "meow";
	else
		sound = "???";
	std::cout << sound << std::endl;
}