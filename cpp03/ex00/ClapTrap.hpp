#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <limits.h>
# include "colors.hpp"

class	ClapTrap {

	protected:
		std::string			_name;
		unsigned int		_HP;
		unsigned int const	_maxHP;
		unsigned int		_PP;
		unsigned int		_attackDamage;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ClapTrap (std::string name);
		ClapTrap (ClapTrap const& original);
		~ClapTrap ();
	 
	 	// OPERATORS
		ClapTrap&	operator= (ClapTrap const& right);
		
		// GETTERS / SETTERS
		std::string const	getName () const;
		unsigned int 		getHitPoints () const;
		unsigned int		getEnergyPoints () const;
		unsigned int		getAttackDamage () const;

		// OTHERS
		void				attack (const std::string& target);
		void				takeDamage (unsigned int amount);
		void				beRepaired (unsigned int amount);
		
};


#endif