#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap {

	protected:
		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int const	_maxHitPoints;
		unsigned int		_energyPoints;
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

/* 		void				setHitPoints (unsigned int newPoints);
		void				setEnergyPoints (unsigned int newPoints);
		void				setAttackDamage (unsigned int newPoints); */

		// OTHERS
		void				attack (const std::string& target);
		void				takeDamage (unsigned int amount);
		void				beRepaired (unsigned int amount);
		
};


#endif