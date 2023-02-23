#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string _name;
		using ScavTrap::_PP;
		using FragTrap::_HP;
		using FragTrap::_AD;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const& original);
		~DiamondTrap ();
	 
	 	// OPERATORS
		DiamondTrap&	operator= (ClapTrap const& source);
		
		void ScavTrap::attack ();

		void	whoAmI (void);
};

#endif