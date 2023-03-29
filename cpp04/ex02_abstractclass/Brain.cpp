#include "Brain.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Brain::Brain () {

	for (int i = 0; i < 100; i++)
		_ideas [i] = "*nothing*";
	announce ("constructor");
}

Brain::Brain (Brain const& original) { 
	
	*this = original;
	announce ("copy constructor");
}

Brain::~Brain () {

	announce ("destructor");
}

// OPERATOR = 
Brain&	Brain::operator= (Brain const& rhs) {

	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			_ideas [i] = rhs.getIdea (i);
	}
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string const&	Brain::getIdea (int i) const {
	
	return _ideas [i];
}

void		Brain::setIdea (int i, std::string idea) { 
	
	if (i >= 0 && i < 100 && !idea.empty ())
		_ideas [i] = idea;
	 
}

/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Brain::announce (std::string const func) const {

	std::cout << "Brain " << func << " called" << std::endl;
}

void	Brain::displayIdea (int i) const {

	i >= 0 && i < 100 ?
		std::cout << _ideas[i] << std::endl
		: std::cout << "please enter a value between 0 and 99" << std::endl;

}