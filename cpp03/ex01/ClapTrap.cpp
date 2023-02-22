#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_HP (10),
										_maxHP (_HP),
										_PP (10),
										_attackDamage (0) {

	std::cout << "ClapTrap " << _name << " is born 👾" << std::endl; }

ClapTrap::ClapTrap (ClapTrap const& original) :	_name (original.getName ()),
												_HP (original.getHitPoints ()),
												_maxHP (_HP),
												_PP (original.getEnergyPoints ()),
												_attackDamage (original.getAttackDamage ()) {	

	_name += "copy";
	std::cout << "ClapTrap " << _name << " is born 👾👾" << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << "ClapTrap " << _name << " is destructed by the player 🌠" << std::endl;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string const	ClapTrap::getName () const {

	std::string const name = _name;
	return name;
}

unsigned int		ClapTrap::getHitPoints () const {

	return _HP;
}

unsigned int		ClapTrap::getEnergyPoints () const {

	return _PP;
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

	if (_HP > 0)
	{
		t_ll res = (t_ll) _HP - (t_ll) amount;
		res = res < 0 ? 0 : res;
		_HP = res;
		std::cout << _name << " loses " << amount << GREY << " -> HP now is " << _HP << NEUTRAL << std::endl;
	}
	else
		std::cout << _name << " is already on the ground ! leave them alone 😵" << std::endl;
}

void	ClapTrap::beRepaired (unsigned int amount) {

	if (_PP)
	{
		std::cout << _name << " uses beRepaired. ";
		t_ul res = (t_ul) _HP + (t_ul) amount;
		res = res > _maxHP ? _maxHP : res;
		_HP = res;
		_HP == _maxHP ?
			std::cout 	<< _name << "'s HP are maxed out !" << GREY << " -> HP now is " << _HP << NEUTRAL << std::endl
			: std::cout << _name << " is repaired of " << amount << GREY << " -> HP now is " << _HP << NEUTRAL << std::endl;
		_PP--;
	}
	else
		std::cout << "🚫" << _name << " cant be repaired coz no PP anymore x_x 🚫" << std::endl;
}

void	ClapTrap::attack (const std::string& target)
{
	if (_HP)
	{
		_PP-- ?
			std::cout 	<< _name << " attacks " << target << ",  aiming to cause " << _attackDamage << " points of damage! "<< std::endl
			: std::cout 	<< "🚫 " << _name << " cant attack " << target << " coz no PP anymore x_x 🚫" << std::endl;
	}
	else
		std:: cout	<< _name << " tries to attack "<< target << " but they just crawl sadly in their blood " << std::endl;
}
