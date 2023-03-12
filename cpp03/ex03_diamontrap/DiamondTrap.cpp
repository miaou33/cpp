#include "DiamondTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

DiamondTrap::DiamondTrap (std::string name) : ClapTrap (name + "_clap_name"), ScavTrap (name), FragTrap (name) {

	_name = name;
	FragTrap::setDefaultHP ();
	ScavTrap::setDefaultPP ();
	FragTrap::setDefaultAD ();
	setMaxHP ();
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

void	DiamondTrap::setMaxHP () {
	
	_maxHP = _HP;
}

/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	DiamondTrap::whoAmI (void) {

	FragTrap::_HP ?
		std::cout << "🔮 " << this->getName () << " speaks : \"my grand parent name is " << ClapTrap::_name << ", and mine is " << _name << "\" 🔮" <<  std::endl
		: std:: cout << "🔮 " << this->getName () << " tries to do a speak but they just crawl in their blood 🔮" << std::endl;
}
