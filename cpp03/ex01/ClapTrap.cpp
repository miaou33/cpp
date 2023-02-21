#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_hitPoints (10),
										_maxHitPoints (_hitPoints),
										_energyPoints (10),
										_attackDamage (0) {

	std::cout << "ClapTrap " << _name << " is born 👾" << std::endl; }

ClapTrap::ClapTrap (ClapTrap const& original) :	_name (original.getName ()),
												_hitPoints (original.getHitPoints ()),
												_maxHitPoints (_hitPoints),
												_energyPoints (original.getEnergyPoints ()),
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

	if (_hitPoints > 0)
	{
		int	res = _hitPoints;
		res -= amount < 0 ? 0 : res;
		_hitPoints = res;
		std::cout 	<< _name
					<< " loses " << amount
					<< GREY << " -> HP now is " << _hitPoints << NEUTRAL
					<< std::endl;
	}
	else
	{
		std::cout	<< _name 
					<< " is already on de ground ! leave them alone 😵"
					<< std::endl;
	}
}

void	ClapTrap::beRepaired (unsigned int amount) {

	if (_energyPoints)
	{
		int	res = _energyPoints;
		_energyPoints = --res < 0 ? 0 : res;
		std::cout 	<< _name << " uses beRepaired. ";
		
		unsigned long res1 = _hitPoints + amount;
		_hitPoints = res1 > UINT_MAX ?
						_maxHitPoints : 
						(unsigned int) res1;

		if (_hitPoints >= _maxHitPoints)
		{
			std::cout 	<< _name << "'s HP are maxed out !" 
						<< GREY << " -> HP now is " << _hitPoints << NEUTRAL
						<< std::endl;
			_hitPoints = _maxHitPoints;
		}
		else
			std::cout 	<< _name
						<< " is repaired of "
						<< amount
						<< GREY << " -> HP now is " << _hitPoints << NEUTRAL
						<< std::endl;
	}
	else
	{
		std::cout	<< _name
					<< " cant be repaired coz no PP anymore x_x"
					<< std::endl;
	}
}

void	ClapTrap::attack (const std::string& target)
{

	if (!_hitPoints)
	{
		std:: cout	<< _name << " tries to attack "<< target
					<< " but they just crawl sadly in their blood "
					<< std::endl;
		return ;
	}
	if (_energyPoints)
	{
		int	res = _energyPoints;
		_energyPoints = --res < 0 ? 0 : res;
		std::cout 	<< _name 
					<< " attacks " << target
					<< ",  aiming to cause " << _attackDamage 
					<< " points of damage! "
					<< std::endl;
	}
	else
	{
		std::cout 	<< "🚫 "
					<< _name 
					<< " cant attack " << target 
					<< " coz no PP anymore x_x 🚫"
					<< std::endl;
	}
}
