#include "FragTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

FragTrap::FragTrap () : ClapTrap () {}

FragTrap::FragTrap (std::string name) : ClapTrap (name) {
											_HP = 100;
											_PP = 100;
											_attackDamage = 30;

	std::cout 	<< "... ! FragTrap " << _name << " is born 🌞" << std::endl;
}

FragTrap::FragTrap (FragTrap const& original) : ClapTrap (original) {}

FragTrap::~FragTrap () {

	std::cout 	<< "... FragTrap " << RESET << _name << " is destructed by the player 🕋" << std::endl;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

unsigned int		FragTrap::getHP () const { return _HP; }

unsigned int		FragTrap::getPP () const { return _PP; }

unsigned int		FragTrap::getAttackDamage () const { return _attackDamage; }


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
FragTrap&	FragTrap::operator= (FragTrap const& right) {

	ClapTrap::operator= (right);
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