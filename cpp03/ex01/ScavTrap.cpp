#include "ScavTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ScavTrap::ScavTrap (std::string name) : ClapTrap (name) {
	
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout 	<< "... ! ScavTrap "
				<< _name << " is born 🛸" << std::endl;

}

ScavTrap::ScavTrap (ScavTrap const& original) : ClapTrap (original) {}

ScavTrap::~ScavTrap () {

	std::cout 	<< "... ScavTrap "
				<< NEUTRAL << _name << " is destructed by the player 🎐" << std::endl;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ScavTrap&	ScavTrap::operator= (ScavTrap const& right) {

	ClapTrap::operator= (right);
	return *this;
}
