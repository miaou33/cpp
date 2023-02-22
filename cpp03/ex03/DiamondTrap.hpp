#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	protected:
		using ClapTrap:: _name;
		using FragTrap:: _HP;
		using ScavTrap:: _PP;
		using FragTrap:: _attackDamage;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const& original);
		~DiamondTrap ();
	 
	 	// OPERATORS
		DiamondTrap&	operator= (DiamondTrap const& right);
		
		// GETTERS / SETTERS : inherited by ClapTrap

		void	whoAmI (void);
};


#endif