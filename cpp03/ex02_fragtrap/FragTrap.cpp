#include "FragTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

FragTrap::FragTrap (std::string name) : ClapTrap (name) {
											_HP = 100;
											_PP = 100;
											_AD = 30;

	std::cout << "... ! FragTrap " << _name << " is born" << std::endl;
}

FragTrap::FragTrap (FragTrap const& original) : ClapTrap (original) {

	*this = original;
	std::cout << "... ! a copyFragTrap " << _name << " is born" << std::endl;
}

FragTrap::~FragTrap () {

	std::cout << "... FragTrap " << END << _name << " is destructed by the player" << std::endl;
}

void	FragTrap::setDefaultHP () { _HP = 100; }
void	FragTrap::setDefaultPP () { _PP = 100; }
void	FragTrap::setDefaultAD () { _AD = 30; }

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
FragTrap&	FragTrap::operator= (ClapTrap const& source) {

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

void	FragTrap::attack (const std::string& target)
{
	if (_HP)
		_PP-- ?
			std::cout << _name << " uses frag special attack on " << target << ", aiming to cause " << _AD << " points of damage ! "
			: std::cout << "❌ " << _name << " cant attack " << target << " coz no PP anymore x_x ❌" << std::endl;
	else
		std:: cout	<< _name << " tries to attack "<< target << " but they just crawl sadly in their blood" << std::endl;
}

void	FragTrap::highFivesGuys (void) {

	_HP ?
		std::cout << _name << " does a High Five ! nothing happens" << std::endl
		: std::cout << _name << " tries to do a High Five but they just crawl sadly in their blood" << std::endl;
}