#include "DiamondTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

DiamondTrap::DiamondTrap (std::string name) : ClapTrap (name + "_clap_name"), ScavTrap (name), FragTrap (name) {

	_name = name;
	FragTrap::setDefaultHP ();
	ScavTrap::setDefaultPP ();
	FragTrap::setDefaultAD ();
	std::cout << "...... ! DiamondTrap " << _name << " is born 👾" << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const& original) : ClapTrap (original), ScavTrap (original), FragTrap (original) {

	*this = original;
	std::cout << "...... ! DiamondTrap " << _name << " is born 👾" << std::endl;
}

DiamondTrap::~DiamondTrap () {

	std::cout << "...... DiamondTrap " << END << _name << " is destructed by the player 🌠" << std::endl;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

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
/* 						OTHERS						 */
/* ************************************************* */

void	DiamondTrap::whoAmI (void) {

	FragTrap::_HP ?
		std::cout << _name << " asks themself who they are. They remember their two names : " << ClapTrap::_name << ", and " << _name << std::endl
		: std::cout << _name << " tells their two names while agonizing : '" << ClapTrap::_name << "', and '" << _name  << "'"<< std::endl;
}