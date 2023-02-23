#include "ScavTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ScavTrap::ScavTrap (std::string name) : ClapTrap (name) {
											_HP = 100;
											_PP = 50;
											_AD = 20;

	std::cout 	<< "... ! ScavTrap " << _name << " is born 🛸" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const& original) : ClapTrap (original) {}

ScavTrap::~ScavTrap () {

	std::cout 	<< "... ScavTrap " << RESET << _name << " is destructed by the player 🎐" << std::endl;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ScavTrap&	ScavTrap::operator= (ScavTrap const& source) {

	ClapTrap::operator= (source);
	return *this;
}

/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	ScavTrap::guardGate (void) {

	_HP ?
		std::cout	<< _name << " guards the gate ! the gate is guarded" << std::endl
		: std::cout << _name << " tries to do guardGate but they just crawl sadly in their blood" << std::endl;
}