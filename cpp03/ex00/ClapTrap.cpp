#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_hitPoints (10),
										_maxHitPoints (_hitPoints),
										_energyPoints (10),
										_attackDamage (0) {

	std::cout << "ClapTrap " << _name << " is born 👾" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const& original) :	_name (original.getName ()),
												_hitPoints (original.getHitPoints ()),
												_maxHitPoints (_hitPoints),
												_energyPoints (original.getEnergyPoints ()),
												_attackDamage (original.getAttackDamage ()) {	

	std::cout << "ClapTrap clone of " << _name << " is born 👾👾" << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << "ClapTrap " << _name << " is dead 🌠" << std::endl;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string const	ClapTrap::getName () const {

	std::string const name = _name;
	return name;
}

unsigned int		ClapTrap::getHitPoints () const {

	return _hitPoints;
}

unsigned int		ClapTrap::getEnergyPoints () const {

	return _energyPoints;
}

unsigned int		ClapTrap::getAttackDamage () const {

	return _attackDamage;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ClapTrap&	ClapTrap::operator= (ClapTrap const& right) {

	if (this == &right)
		return (*this);
	right.~ClapTrap();
	new (this) ClapTrap (right);
	return *this;
}


/* ************************************************* */
/* 						OTHERS				 		 */
/* ************************************************* */

void	ClapTrap::takeDamage (unsigned int amount) {

	if (_hitPoints) {
		std::cout << _name << " loses " << amount << " HP " << std::endl;
		_hitPoints -= amount;
	}
	else {
		std::cout << _name << " is already dead ! leave him alone" << std::endl;
	}
}

void	ClapTrap::beRepaired (unsigned int amount) {

	if (_energyPoints)
	{
		_energyPoints--;
		_hitPoints ++;
		if (_hitPoints >= _maxHitPoints)
		{
			std::cout << _name << "'s HP are maxed out !" << std::endl;
			_hitPoints = _maxHitPoints;
		}
		else
			std::cout << _name << " is repaired of " << amount << std::endl;
	}
	else
	{
		std::cout << _name << " cant be repaired coz no PP anymore x_x" << std::endl;
	}
}

void	ClapTrap::attack (const std::string& target) {

	if (_energyPoints) {
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else {
		std::cout << _name << " cant attack " << target << "coz no PP anymore x_x" << std::endl;
		_energyPoints--;
	}
}
