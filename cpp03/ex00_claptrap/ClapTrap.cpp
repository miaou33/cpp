#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

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

std::ostream&	operator<< (std::ostream& o, ClapTrap const& source) {

	o << source.getName ()
		<< GREY << " " << source.getHP () << " HP | " 
		<< source.getPP () << " PP | " 
		<< source.getAD () << " AD " << END;
	return (o);
}

/* ************************************************* */
/* 						OTHERS				 		 */
/* ************************************************* */

void	ClapTrap::attack (const std::string& target)
{
	if (_HP)
	{
		_PP ?
			std::cout << "💥 " << _name << " attacks " << target << " 💥" << std::endl
			: std::cout << "❌ " << _name << " cant attack " << target << " coz no PP ❌" << std::endl;

		t_ll res = (t_ll) _PP--;
		_PP = res >= 0 ? (t_ui) res : 0;

	}
	else
		std::cout << "💀 " << _name << " tries to attack "<< target << " but they just crawl in their blood" << " 💀" << std::endl;
}

void	ClapTrap::takeDamage (t_ui amount) {

	if (_HP)
	{
		t_ll res = (t_ll) _HP - (t_ll) amount;
		res = res < 0 ? 0 : res;
		_HP = res;
		_HP ?
			std::cout << "\t\t⤷ " << _name << " loses " << amount << std::endl
			: std::cout << "\t\t⤷ " << _name << " is KO" << std::endl;
	}
	else
		std::cout << _name << " is already KO x_x" << std::endl;
}

void	ClapTrap::beRepaired (t_ui amount) {

	if (_HP)
	{
		if (_PP)
		{
			std::cout << "✨ " << _name << " uses beRepaired ✨" << std::endl;
			t_ul res = _HP + amount;
			res = res > _maxHP ? _maxHP : res;
			_HP = res;
			_HP == _maxHP ?
				std::cout << "\t\t⤷ " << _name << "'s HP are maxed out !" << " " << std::endl
				: std::cout << "\t\t⤷ " << _name << " is repaired of " << amount << std::endl;
			_PP--;
		}
		else
			std::cout << "❌ " << _name << " cant be repaired coz no PP ❌" << std::endl;
	}
	else
		std::cout << "💀 " << _name << " tries to repair themself but they just crawl in their blood" << " 💀" << std::endl;
}
