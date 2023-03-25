#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap () :	_name ("Anon"),
						_HP (10),
						_PP (10),
						_AD (0) {

	_maxHP = _HP;
	std::cout << "ClapTrap constructor called" << std::endl; 
}

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_HP (10),
										_PP (10),
										_AD (0) {

	_maxHP = _HP;
	std::cout << "ClapTrap constructor called" << std::endl; 
}

ClapTrap::ClapTrap (ClapTrap const& original) {	

	*this = original;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << "ClapTrap destructor called" << std::endl;
}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string const	ClapTrap::getName () const {

	return (std::string const) _name;
}

t_ui	ClapTrap::getHP () const {
	
	return _HP; 
}

t_ui	ClapTrap::getPP () const {
	
	return _PP;
}

t_ui	ClapTrap::getAD () const {
	
	return _AD;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
ClapTrap&	ClapTrap::operator= (ClapTrap const& source) {

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
/* 						OTHERS				 		 */
/* ************************************************* */

void	ClapTrap::attack (const std::string& target)
{
	if (_HP)
	{
		_PP--?
			std::cout << this->getName () << " attacks " << target << std::endl
			: std::cout << this->getName () << " cant attack " << target << " coz no PP" << std::endl;

	}
	else
		std::cout << this->getName () << " tries to attack "<< target << " but they are already KO" << std::endl;
}

void	ClapTrap::takeDamage (t_ui amount) {

	if (_HP)
	{
		t_ll res = (t_ll) _HP - (t_ll) amount;
		res = res < 0 ? 0 : res;
		_HP = res;
		_HP ?
			std::cout << "\t\t⤷ " << this->getName () << " loses " << amount << std::endl
			: std::cout << "\t\t⤷ " << this->getName () << " is KO" << std::endl;
	}
	else
		std::cout << this->getName () << " is already KO" << std::endl;
}

void	ClapTrap::beRepaired (t_ui amount) {

	if (_HP)
	{
		if (_PP)
		{
			std::cout << this->getName () << " uses beRepaired" << std::endl;
			t_ul res = _HP + amount;
			res = res > _maxHP ? _maxHP : res;
			_HP = res;
			_HP == _maxHP ?
				std::cout << "\t\t⤷ " << this->getName () << "'s HP are maxed out" << " " << std::endl
				: std::cout << "\t\t⤷ " << this->getName () << " is repaired of " << amount << std::endl;
			_PP--;
		}
		else
			std::cout << this->getName () << " cant be repaired coz no PP" << std::endl;
	}
	else
		std::cout << this->getName () << " tries to repair themself but they are already KO" << std::endl;
}

void	ClapTrap::printStats () {

	std::cout << this->getName () << GREY << " " << _HP << " HP | " << _PP << " PP | " << _AD << " AD " << END << std::endl;
}