#include "Cat.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Cat::Cat () {
	
	_type = "Cat"; 
	_brain = new Brain ();
	announce ("constructor");
}

Cat::Cat (Cat const& original) : AAnimal (original) {
	
	_brain = new Brain (*(original.getBrain ()));
	announce ("copy constructor");
}

Cat::~Cat () {

	delete _brain;
	announce ("destructor");
}

// OPERATOR = 
Cat&			Cat::operator= (Cat const& toBecome) {

	if (this != &toBecome)
	{
		_type = toBecome.getType ();
		(*_brain) = *(toBecome.getBrain ());
	}
	announce ("assignment operator");
	return *this;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Brain*			Cat::getBrain () const { 
	
	return _brain;
}

std::string		Cat::getIdea (int i) const {
	
	return _brain->getIdea (i);
}

void			Cat::setIdea (int i, std::string idea) {

	_brain->setIdea (i, idea);
}

void			Cat::displayIdea (int i) const {

	_brain->displayIdea (i);
}


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void			Cat::announce (std::string const func) const {

	std::cout << "Cat " << func << " called" << std::endl;
}

void			Cat::makeSound () const {

	std::cout << "meow" << std::endl;
}