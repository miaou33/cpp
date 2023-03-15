#include "ScavTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ScavTrap::ScavTrap () {

	_name = "AnonScav";
	setDefaultHP ();
	setDefaultPP ();
	setDefaultAD ();
	std::cout << "...ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap (std::string name) {

	_name = name;
	setDefaultHP ();
	setDefaultPP ();
	setDefaultAD ();
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
	_maxHP = _HP;
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
	{
		_PP ?
			std::cout << this->getName () << " uses scav special attack on " << target << std::endl
			: std::cout << _name << " cant attack " << target << " coz no PP anymore" << std::endl;
	
		t_ll res = (t_ll) _PP--;
		_PP = res >= 0 ? (t_ui) res : 0;
	}
	else
		std::cout << _name << " tries to attack "<< target << " but they are already KO" << std::endl;
}

void	ScavTrap::guardGate (void) {

	_HP ?
		std::cout << _name << " guards the gate\n\t\t⤷ the gate is safe" << std::endl
		: std::cout << _name << " tries to do guardGate but they are already KO" << std::endl;
}