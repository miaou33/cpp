#include "FragTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

FragTrap::FragTrap () : ClapTrap () {}

FragTrap::FragTrap (std::string name) : ClapTrap (name) {
											_HP = 100;
											_PP = 100;
											_AD = 30;

	std::cout 	<< "... ! FragTrap " << _name << " is born" << std::endl;
}

FragTrap::FragTrap (FragTrap const& original) : ClapTrap (original) {

	*this = original;
	std::cout 	<< "... ! a copyFragTrap " << _name << " is born" << std::endl;
}

FragTrap::~FragTrap () {

	std::cout 	<< "... FragTrap " << RESET << _name << " is destructed by the player" << std::endl;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
FragTrap&	FragTrap::operator= (ClapTrap const& source) {

	_name = source.getName ();
	_HP = source.getHP ();
	_PP = source.getPP ();
	_AD = source.getAD ();
	return *this;
}

/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	FragTrap::highFivesGuys (void) {

	_HP ?
		std::cout	<< _name << " does a High Five ! nothing happens" << std::endl
		: std::cout << _name << " tries to do a High Five but they just crawl sadly in their blood" << std::endl;
}