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
												_HP (original.getHP ()),
												_maxHP (_HP),
												_PP (original.getPP ()),
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

unsigned int		ClapTrap::getHP () const {

	return _HP;
}

unsigned int		ClapTrap::getPP () const {

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
		int	res = _HP;
		res -= amount < 0 ? 0 : res;
		_HP = res;
		std::cout 	<< _name
					<< " loses " << amount
					<< GREY << " -> HP now is " << _HP << NEUTRAL
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

	if (_PP)
	{
		int	res = _PP;
		_PP = --res < 0 ? 0 : res;
		std::cout 	<< _name << " uses beRepaired. ";
		
		t_ul res1 = _HP + amount;
		_HP = res1 > UINT_MAX ?
						_maxHP : 
						(unsigned int) res1;

		if (_HP >= _maxHP)
		{
			std::cout 	<< _name << "'s HP are maxed out !" 
						<< GREY << " -> HP now is " << _HP << NEUTRAL
						<< std::endl;
			_HP = _maxHP;
		}
		else
			std::cout 	<< _name
						<< " is repaired of "
						<< amount
						<< GREY << " -> HP now is " << _HP << NEUTRAL
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

	if (!_HP)
	{
		std:: cout	<< _name << " tries to attack "<< target
					<< " but they just crawl sadly in their blood "
					<< std::endl;
		return ;
	}
	if (_PP)
	{
		int	res = _PP;
		_PP = --res < 0 ? 0 : res;
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
