#include "DiamondTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

DiamondTrap::DiamondTrap (std::string name) : ClapTrap (name + "_clap_name"), ScavTrap (name), FragTrap (name) {

	_name = name;
/* 	_HP = FragTrap::_HP;
	_PP = ScavTrap::_PP;
	_AD = FragTrap::_AD; */
	std::cout 	<< "...... ! DiamondTrap " << _name << " is born" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const& original) : ClapTrap (original), ScavTrap (original), FragTrap (original) {

	*this = original;
	std::cout 	<< "...... ! DiamondTrap " << _name << " is born" << std::endl;
}

DiamondTrap::~DiamondTrap () {

	std::cout 	<< "...... DiamondTrap " << RESET << _name << " is destructed by the player" << std::endl;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
DiamondTrap&	DiamondTrap::operator= (ClapTrap const& source) {

	_name = source.getName ();
	_HP = source.getHP ();
	_PP = source.getPP ();
	_AD = source.getAD ();
	return *this;
}


/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	DiamondTrap::whoAmI (void) {

	_HP ?
		std::cout	<< _name << " asks themself who they are. the answer is double : " << ClapTrap::_name << ", and " << _name << std::endl
		: std::cout << _name << " asks themself who they are, crawling sadly in their blood" << std::endl;
}