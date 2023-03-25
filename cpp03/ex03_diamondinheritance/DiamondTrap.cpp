#include "DiamondTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

DiamondTrap::DiamondTrap (std::string name) {

	_name = name;
	FragTrap::setDefaultHP ();
	ScavTrap::setDefaultPP ();
	FragTrap::setDefaultAD ();
	std::cout << "......DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const& original) : ClapTrap (original), ScavTrap (original), FragTrap (original) {

	*this = original;
	std::cout << "......DiamondTrapcopy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap () {

	std::cout << "......DiamondTrap destructor called" << std::endl;
}


// ASSIGNMENT
DiamondTrap&	DiamondTrap::operator= (ClapTrap const& source) {

	if (this != &source)
	{
		_name = source.getName ();
		_HP = source.getHP ();
		_PP = source.getPP ();
		_AD = source.getAD ();
	}
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string const	DiamondTrap::getName () const {

	return (std::string const) _name;
}


/* ************************************************* */
/* 						NON MB FUNCTIONS			 */
/* ************************************************* */

void	DiamondTrap::whoAmI (void) {

	_HP ?
		std::cout << this->getName () << "'s subobject name is " << ClapTrap::_name << ", and them is " << _name <<  std::endl
		: std:: cout << this->getName () << " tries to do a speak but they are already KO" << std::endl;
}
