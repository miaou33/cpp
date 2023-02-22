#include "DiamondTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

DiamondTrap::DiamondTrap (std::string name) : ClapTrap (name + "_clap_name"), ScavTrap (name), FragTrap (name) {

	_name = name;
	_HP = FragTrap::getHP ();
	_PP = ScavTrap::getPP ();
	_attackDamage = FragTrap::getAttackDamage ();

	std::cout 	<< "...... ! DiamondTrap " << _name << " is born 🛸" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const& original) : ClapTrap (original), ScavTrap (original), FragTrap (original) {}

DiamondTrap::~DiamondTrap () {

	std::cout 	<< "...... DiamondTrap " << RESET << _name << " is destructed by the player 🎐" << std::endl;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
DiamondTrap&	DiamondTrap::operator= (DiamondTrap const& right) {

	ClapTrap::operator= (right);
	return *this;
}

/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	DiamondTrap::whoAmI (void) {

	_HP ?
		std::cout	<< _name << " asks themself who they are" << std::endl
		: std::cout << _name << " asks themself who they are, crawling sadly in their blood" << std::endl;
}