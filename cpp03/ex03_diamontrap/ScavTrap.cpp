#include "ScavTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ScavTrap::ScavTrap (std::string name) : ClapTrap (name) {

	_HP = 100;
	_PP = 50;
	_AD = 20;
	_maxHP = _HP;
	std::cout << "...ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const& original) : ClapTrap (original) {

	*this = original;
	std::cout << "...ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap () {

	std::cout << "...ScavTrap destructor called" << std::endl;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ScavTrap&	ScavTrap::operator= (ClapTrap const& source) {

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

std::string const	ScavTrap::getName () const {

	return (std::string const) _name;
}

void	ScavTrap::setDefaultHP () {
	
	_HP = 100;
}

void	ScavTrap::setDefaultPP () {
	
	_PP = 50;
}

void	ScavTrap::setDefaultAD () {
	
	_AD = 20;
}


/* ************************************************* */
/* 						OTHERS						 */
/* ************************************************* */

void	ScavTrap::attack (const std::string& target)
{
	if (_HP)
		_PP-- ?
			std::cout << "🛸 " << this->getName () << " uses scav special attack on " << target << " 🛸" << std::endl
			: std::cout << "❌ " << _name << " cant attack " << target << " coz no PP anymore x_x ❌" << std::endl;
	else
		std::cout << "💀 " << _name << " tries to attack "<< target << " but they just crawl in their blood" << " 💀" << std::endl;
}

void	ScavTrap::guardGate (void) {

	_HP ?
		std::cout << "⛄ " << _name << " guards the gate ! ⛄\n\t\t⤷ the gate is safe" << std::endl
		: std::cout << "💀 " << _name << " tries to do guardGate but they just crawl sadly in their blood 💀" << std::endl;
}