#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include <string>
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string 	_name;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		DiamondTrap (std::string name);
		DiamondTrap (DiamondTrap const& original);
		~DiamondTrap ();
		DiamondTrap&	operator= (ClapTrap const& source);

		virtual std::string const	getName () const;
		using	ScavTrap::attack;
		void	whoAmI (void);
};

#endif