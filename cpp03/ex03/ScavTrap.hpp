#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ScavTrap ();
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const& original);
		~ScavTrap ();
	 
	 	// OPERATORS
		ScavTrap&	operator= (ScavTrap const& right);
		
		// GETTERS / SETTERS : inherited by ClapTrap

		void	guardGate (void);
};


#endif