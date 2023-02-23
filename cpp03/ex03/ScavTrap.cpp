#include "ScavTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ScavTrap::ScavTrap () : ClapTrap () {}

ScavTrap::ScavTrap (std::string name) : ClapTrap (name) {
											_HP = 100;
											_PP = 0;
											_AD = 20;

	std::cout 	<< "... ! ScavTrap " << _name << " is born" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const& original) : ClapTrap (original) {

	*this = original;
	std::cout 	<< "... !  a copyScavTrap " << _name << " is born" << std::endl;
}

ScavTrap::~ScavTrap () {

	std::cout 	<< "... ScavTrap " << RESET << _name << " is destructed by the player" << std::endl;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ScavTrap&	ScavTrap::operator= (ClapTrap const& source) {

	_name = source.getName ();
	_HP = source.getHP ();
	_PP = source.getPP ();
	_AD = source.getAD ();
	return *this;
}

/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	ClapTrap::attack (const std::string& target)
{
	if (_HP)
	{
		_PP-- ?
			std::cout 	<< _name << " attacks " << target << ",  aiming to cause " << _AD << " points of damage! "<< std::endl
			: std::cout 	<< "🚫 " << _name << " cant attack " << target << " coz no PP anymore x_x 🚫" << std::endl;
	}
	else
		std:: cout	<< _name << " tries to attack "<< target << " but they just crawl sadly in their blood " << std::endl;
}

void	ScavTrap::guardGate (void) {

	_HP ?
		std::cout	<< _name << " guards the gate ! the gate is guarded" << std::endl
		: std::cout << _name << " tries to do guardGate but they just crawl sadly in their blood" << std::endl;
}