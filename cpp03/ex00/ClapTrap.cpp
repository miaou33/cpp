#include "ClapTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

ClapTrap::ClapTrap (std::string name) :	_name (name),
										_HP (10),
										_PP (10),
										_AD (0) {
	std::cout << "ClapTrap " << _name << " is born 👾" << std::endl; 
}

ClapTrap::ClapTrap (ClapTrap const& original) :	_name (original.getName ()),
												_HP (original.getHP ()),
												_PP (original.getPP ()),
												_AD (original.getAD ()) {	

	std::cout << "ClapTrap " << _name << " is born 👾" << std::endl;
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

t_ui	ClapTrap::getHP () const { return _HP; }
t_ui	ClapTrap::getPP () const { return _PP; }
t_ui	ClapTrap::getAD () const { return _AD; }

void	ClapTrap::setDefaultHP () { _HP = 10; }
void	ClapTrap::setDefaultPP () { _PP = 10; }
void	ClapTrap::setDefaultAD () { _AD = 0; }

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
		_PP-- ?
			std::cout << _name << " attacks " << target << ", aiming to cause " << _AD << " points of damage! "<< std::endl
			: std::cout << "🚫 " << _name << " cant attack " << target << " coz no PP anymore x_x 🚫" << std::endl;
	}
	else
		std:: cout	<< _name << " tries to attack "<< target << " but they just crawl sadly in their blood " << std::endl;
}

void	ClapTrap::takeDamage (t_ui amount) {

	if (_HP > 0)
	{
		t_ll res = (t_ll) _HP - (t_ll) amount;
		res = res < 0 ? 0 : res;
		_HP = res;
		std::cout << _name << " loses " << amount << std::endl;
	}
	else
		std::cout << _name << " is already on the ground ! leave them alone 😵" << std::endl;
}

void	ClapTrap::beRepaired (t_ui amount) {

	if (_PP)
	{
		std::cout << _name << " uses beRepaired. ";
		t_ul res = _HP + amount;
		res = res > UINT_MAX ? UINT_MAX : res;
		_HP = res;
		_HP == UINT_MAX ?
			std::cout << _name << "'s HP are maxed out !" << std::endl
			: std::cout << _name << " is repaired of " << amount << std::endl;
	}
	else
		std::cout << "🚫" << _name << " cant be repaired coz no PP anymore x_x 🚫" << std::endl;
}
