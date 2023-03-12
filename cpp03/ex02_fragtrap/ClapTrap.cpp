#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_HP (10),
										_PP (10),
										_AD (0) {

	std::cout << "ClapTrap " << _name << " is born" << std::endl; 
}

ClapTrap::ClapTrap (ClapTrap const& original) {	

	*this = original;
	std::cout << "ClapTrap " << _name << " is born" << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << "ClapTrap " << _name << " is destructed by the player" << std::endl;
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
			std::cout << "💥 " << _name << " attacks " << target << ", aiming to cause " << _AD << " points of damage 💥" << std::endl
			: std::cout << "❌ " << _name << " cant attack " << target << " coz no PP anymore x_x ❌" << std::endl;

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
			std::cout << _name << " loses " << amount << std::endl
			: std::cout << "💀 " << _name << " is KO " << " 💀" << std::endl;
	}
	else
		std::cout << _name << " is already KO x_x" << std::endl;
}

void	ClapTrap::beRepaired (t_ui amount) {

	if (_HP)
	{
		if (_PP)
		{
			std::cout << "✨ " << _name << " uses beRepaired. ";
			t_ul res = _HP + amount;
			res = res > UINT_MAX ? UINT_MAX : res;
			_HP = res;
			_HP == UINT_MAX ?
				std::cout << _name << "'s HP are maxed out" << " ✨" << std::endl
				: std::cout << _name << " is repaired of " << amount << " ✨" << std::endl;
			_PP--;
		}
		else
			std::cout << "❌" << _name << " cant be repaired coz no PP anymore x_x ❌" << std::endl;
	}
	else
		std::cout << "💀 " << _name << " tries to repair themself but they just crawl in their blood" << " 💀" << std::endl;
}
