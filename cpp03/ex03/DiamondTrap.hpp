#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string 	_name;
		t_ui	_PP;
		t_ui	_HP;
		t_ui	_AD;
//		DiamondTrap ();

	public:
		// CONSTRUCTORS / DESTRUCTOR
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const& original);
		~DiamondTrap ();
	 
	 	// OPERATORS
		DiamondTrap&	operator= (ClapTrap const& source);
		
		using ScavTrap::attack;

		void	whoAmI (void);
};

#endif